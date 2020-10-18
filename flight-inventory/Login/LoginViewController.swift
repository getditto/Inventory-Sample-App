import UIKit
import DittoKitSwift

final class LoginViewController: UIViewController {

    @IBOutlet private weak var usernameTextField: UITextField!
    @IBOutlet private weak var adminSwitch: UISwitch!
    @IBOutlet private weak var loginButton: UIButton!

    private var isAdmin = false

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
    }

    private func setupUI() {
        title = "Login"
        loginButton.addTarget(self, action: #selector(didTapLogin), for: .touchUpInside)
        loginButton.layer.cornerRadius = 8
    }

    @objc private func didTapLogin() {
        guard let username = usernameTextField.text else {
            showEmptyUsernameAlert(); return
        }
        guard !username.isEmpty else {
            showEmptyUsernameAlert(); return
        }

        DittoKit.deviceName = username

        let userInfo = UserInfo(name: username, isAdmin: adminSwitch.isOn)
        let sb = UIStoryboard(name: "Flight", bundle: nil)
        let destination = sb.instantiateInitialViewController { coder in
            FlightListViewController(coder: coder, userInfo: userInfo)
        }
        if let destination = destination {
            navigationController?.pushViewController(destination, animated: true)
        }
    }

    @objc private func showEmptyUsernameAlert() {
        let alert = UIAlertController(
            title: "Username is Empty",
            message: nil,
            preferredStyle: .alert
        )
        alert.addAction(UIAlertAction(title: "OK", style: .cancel))
        present(alert, animated: true)
    }
}
