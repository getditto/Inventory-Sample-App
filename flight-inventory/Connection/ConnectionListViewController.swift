import UIKit
import DittoKitSwift

final class ConnectionListViewController: UIViewController {

    @IBOutlet private weak var tableView: UITableView!

    private var connections = [Connection]()
    private var peerObserver: DittoPeersObserver?

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
        observePeers()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        peerObserver = nil
    }

    private func setupUI() {
        title = "Connections"
        let nib = UINib(nibName: "ConnectionTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: "ConnectionTableViewCell")
        tableView.tableFooterView = UIView()
        tableView.delegate = self
        tableView.dataSource = self
    }

    private func observePeers() {
        peerObserver = DittoHandler.ditto.observePeers { [weak self] peers in
            guard let self = self else { return }
            self.connections = []
            
            peers.forEach { peer in
                peer.connections.forEach {
                    let connection = Connection(deviceName: peer.deviceName, connectionType: $0)
                    self.connections.append(connection)
                }
            }
            self.tableView.reloadData()
        }
    }
}

extension ConnectionListViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return connections.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ConnectionTableViewCell", for: indexPath) as! ConnectionTableViewCell
        let connection = connections[indexPath.row]
        cell.deviceNameLabel?.text = connection.deviceName
        cell.connectionTypeLabel?.text = connection.connectionType
        return cell
    }
}
