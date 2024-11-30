//
//  ContentView.swift
//  Hiking
//
//  Created by Reinaldo Moraga on 3/3/22.
//

import SwiftUI

struct ContentView: View {
    
    let hikes = Hike.all()
    
    var body: some View {
        NavigationView {
            List(hikes, id: \.name) { hike in
                NavigationLink(destination: HikeDetail(hike: hike)) {
                    HikeCell(hike: hike)
                }
            }
            .listStyle(.plain)
            .navigationTitle("Hikes")
            .navigationBarTitleDisplayMode(.inline)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
