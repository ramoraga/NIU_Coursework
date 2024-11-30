//
//  ContentView.swift
//  ScrollView
//
//  Created by Reinaldo Moraga on 2/15/22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        ScrollView(.vertical, showsIndicators: true) {
            VStack(spacing: 20) {
                ForEach(0..<10) {
                    Text("Item \($0)")
                        .foregroundColor(.white)
                        .font(.largeTitle)
                        .frame(width: 200, height: 200)
                        .background(Color.mint)
                }
            }
        }
        .frame(height: 350)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
