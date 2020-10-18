import Foundation
import DittoKitSwift

final class DittoHandler {
    private static let accessLicense = "Insert your access license!"

    static private(set) var ditto: DittoKit = {
        DittoKit.minimumLogLevel = .debug
        let ditto = DittoKit(identity: .development(appName: "live.ditto.flight-inventory"))
        ditto.setAccessLicense(DittoHandler.accessLicense)
        ditto.start(transports: [.awdl, .bluetooth, .wifi])
        return ditto
    }()
}
