//
//  ContentView.swift
//  Pickers
//
//  Created by Reinaldo Moraga on 2/22/22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        TabView {
            SegmentedControlView()
                .tabItem {
                    Label("Ice Cream", image: "Cone")
                }
            SinglePickerView()
                .tabItem {
                    Label("Star Wars", image: "R2-D2")
                }
            DoublePickerView()
                .tabItem {
                    Label("Lunch", image: "Sandwich")
                }
            DatePickerView()
                .tabItem {
                    Label("Date", image: "Calendar")
                }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
