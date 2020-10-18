import UIKit

final class InventoryTableViewCell: UITableViewCell {
    @IBOutlet private(set) weak var nameLabel: UILabel!
    @IBOutlet private(set) weak var countLabel: UILabel!
    @IBOutlet private(set) weak var stepper: CustomStepper! {
        didSet {
            stepper.minimumValue = 0
            stepper.maximumValue = 99
        }
    }
}

final class CustomStepper: UIStepper {
    var indexPath: IndexPath?
}
