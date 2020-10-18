import UIKit

final class FlightListViewController: UIViewController {
    @IBOutlet private var flightButtons: [UIButton]!

    private let userInfo: UserInfo

    init?(coder: NSCoder, userInfo: UserInfo) {
        self.userInfo = userInfo
        super.init(coder: coder)
    }

    required init?(coder: NSCoder) {
        fatalError()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
    }

    private func setupUI() {
        title = "Flight List"

        flightButtons.forEach {
            $0.layer.cornerRadius = 8
            $0.addTarget(self, action: #selector(didTapFlightButton), for: .touchUpInside)
        }
    }

    @objc private func didTapFlightButton(_ sender: UIButton) {
        let flightInfo = FlightInfo(name: sender.titleLabel?.text ?? "")

        let sb = UIStoryboard(name: "Inventory", bundle: nil)
        let destination = sb.instantiateInitialViewController { coder in
            InventoryViewController(coder: coder, userInfo: self.userInfo, flightInfo: flightInfo)
        }
        if let destination = destination {
            navigationController?.pushViewController(destination, animated: true)
        }
    }
}
