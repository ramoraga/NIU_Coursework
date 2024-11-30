//
//  ContentView.swift
//  BindingDemo
//
//  Created by Reinaldo Moraga on 3/22/22.
//

import SwiftUI

struct ContentView: View {
    
    @State private var users = ["monsterup", "bookman", "simmson"]
    @State private var showAddUser = false
    
    var body: some View {
        
        NavigationView {
            List {
                ForEach(users, id: \.self) { user in
                    Text(user)
                }
            }
            .navigationTitle("Users")
            .toolbar {
                ToolbarItem(placement: .primaryAction) {
                    Button(action: { showAddUser = true },
                           label: { Image(systemName: "plus")})
                }
            }
        }
        .sheet(isPresented: $showAddUser) {
            AddUserView(isPresented: $showAddUser, users: $users)
            EmptyView()
        }
        .navigationViewStyle(.stack)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
