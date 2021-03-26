import UIKit
import DittoSwift

final class InventoryViewController: UIViewController {
    @IBOutlet private weak var tableView: UITableView!

    private let userInfo: UserInfo
    private let flightInfo: FlightInfo

    private var liveQuery: DittoLiveQuery?
    private var inventories = [DittoDocument]()

    private var collection: DittoCollection {
        return DittoHandler.ditto.store.collection(flightInfo.name)
    }

    init?(coder: NSCoder, userInfo: UserInfo, flightInfo: FlightInfo) {
        self.userInfo = userInfo
        self.flightInfo = flightInfo
        super.init(coder: coder)
    }

    required init?(coder: NSCoder) {
        fatalError()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
        observe()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        observe()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        liveQuery?.stop()
        liveQuery = nil
    }

    private func setupUI() {
        title = flightInfo.name
        let nib = UINib(nibName: "InventoryTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: "InventoryTableViewCell")
        tableView.tableFooterView = UIView()
        tableView.delegate = self
        tableView.dataSource = self

        navigationItem.rightBarButtonItem = UIBarButtonItem(
            image: UIImage(systemName: "ellipsis"),
            style: .done,
            target: self,
            action: #selector(didTapMore)
        )
    }

    private func observe() {
        liveQuery = collection.findAll().observe { [weak self] docs, event in
            guard let self = self else { return }
            self.inventories = docs
            self.tableView.reloadData()
        }
    }

    @objc private func didTapStepper(_ sender: CustomStepper) {
        guard let indexPath = sender.indexPath else { return }
        let newCount = sender.value
        let inventory = inventories[indexPath.row]
        let oldCount = Double(inventory["count"].intValue)
        let gap = newCount - oldCount

        collection.findByID(inventory.id).update { doc in
            doc?["count"].replaceWithCounter()
            doc?["count"].increment(amount: gap)
        }

        tableView.reloadRows(at: [indexPath], with: .none)
    }
}

extension InventoryViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return inventories.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "InventoryTableViewCell", for: indexPath) as! InventoryTableViewCell
        let inventory = inventories[indexPath.row]
        cell.nameLabel.text = inventory["name"].stringValue

        let count = inventory["count"].intValue
        cell.countLabel.text = String(count)
        cell.stepper.addTarget(self, action: #selector(didTapStepper), for: .valueChanged)
        cell.stepper.indexPath = indexPath
        cell.stepper.value = Double(count)

        return cell
    }
}

// MARK: - More Button
extension InventoryViewController {
    @objc private func didTapMore() {
        let alert = UIAlertController(title: nil, message: nil, preferredStyle: .actionSheet)
        alert.addAction(UIAlertAction(title: "Add Inventory", style: .default) { _ in
            self.didTapAdd()
        })
        alert.addAction(UIAlertAction(title: "Show Connection", style: .default) { _ in
            self.didTapConnection()
        })
        alert.addAction(UIAlertAction(title: "Remove All Inventory", style: .destructive) { _ in
            self.didTapRemoveAll()
        })
        alert.addAction(UIAlertAction(title: "Logout", style: .destructive) { _ in
            self.didTapLogout()
        })

        if UIDevice.current.userInterfaceIdiom == .pad {
            alert.popoverPresentationController?.sourceView = view
            alert.popoverPresentationController?.sourceRect = CGRect(x: view.bounds.midX, y: view.bounds.midY, width: 0, height: 0)
            alert.popoverPresentationController?.permittedArrowDirections = []
        }

        present(alert, animated: true)
    }

    @objc private func didTapAdd() {
        guard userInfo.isAdmin else {
            showNonAdminAlert(); return
        }

        let alert = UIAlertController(title: "New Inventory", message: nil, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))

        alert.addAction(UIAlertAction(title: "OK", style: .default) { [weak self] _ in
            guard let self = self else { return }
            guard let text = alert.textFields?.first?.text else { return }

            guard !text.isEmpty else {
                self.didTapAdd(); return
            }

            let docID = try? self.collection.insert(
                ["name": text, "count": 0]
            )

            if let docID = docID {
                self.collection.findByID(docID).update { doc in
                    doc?["count"].replaceWithCounter(isDefault: true)
                }
            }

            self.tableView.reloadData()
        })

        alert.addTextField { field in
            field.placeholder = "New inventory name"
            field.keyboardType = .default
        }
        present(alert, animated: true)
    }

    @objc private func didTapRemoveAll() {
        guard userInfo.isAdmin else {
            showNonAdminAlert(); return
        }

        let alert = UIAlertController(
            title: "Do you want to remove all?",
            message: nil,
            preferredStyle: .alert
        )
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        alert.addAction(UIAlertAction(title: "OK", style: .destructive) { [weak self] _ in
            guard let self = self else { return }
            self.collection.findAll().remove()
        })
        present(alert, animated: true)
    }

    @objc private func didTapConnection() {
        let sb = UIStoryboard(name: "Connections", bundle: nil)
        let destination = sb.instantiateInitialViewController { coder in
            ConnectionListViewController(coder: coder)
        }
        if let destination = destination {
            navigationController?.pushViewController(destination, animated: true)
        }
    }

    @objc private func didTapLogout() {
        navigationController?.popToRootViewController(animated: true)
    }

    private func showNonAdminAlert() {
        let alert = UIAlertController(
            title: "Editing is only allowed to admin",
            message: nil,
            preferredStyle: .alert
        )
        alert.addAction(UIAlertAction(title: "OK", style: .cancel))
        present(alert, animated: true)
    }
}
