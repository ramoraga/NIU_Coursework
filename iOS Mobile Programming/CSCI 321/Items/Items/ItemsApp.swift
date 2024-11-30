//
//  ItemsApp.swift
//  Items
//
//  Created by Reinaldo Moraga on 4/7/22.
//

import SwiftUI

@main
struct ItemsApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
