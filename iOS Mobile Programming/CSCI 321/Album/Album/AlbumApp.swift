//
//  AlbumApp.swift
//  Album
//
//  Created by Rami Lake on 4/29/22.
//

import SwiftUI

@main
struct AlbumApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
