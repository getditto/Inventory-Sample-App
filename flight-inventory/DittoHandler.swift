import Foundation
import DittoSwift

final class DittoHandler {
    private static let accessLicense = "Insert your access license!"

    static private(set) var ditto: Ditto = {
        // You can set a log level
        DittoLogger.minimumLogLevel = .debug

        // App name for the Ditto SDK
        // `let ditto = Ditto()`
        let ditto = Ditto(identity: .development(appName: "live.ditto.flight-inventory"))

        // Set your access license
        ditto.setAccessLicense(DittoHandler.accessLicense)

        // Choose sync transports. Adding all is recommended for the best performance!
        ditto.start(transports: [.awdl, .bluetooth, .wifi])

        return ditto
    }()
}
