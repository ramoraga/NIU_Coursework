//
//  ContentView.swift
//  Label
//
//  Created by Reinaldo Moraga on 2/15/22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {

        VStack(spacing: 20)  {
            
            Image("chicken")
                .resizable()
                .frame(width: 100, height: 90)
            
            Label("Welcome to SwiftUI", systemImage: "star")
                .font(.title.italic())
            
            Label("Paul Hudson")
                .foregroundColor(.blue)
                .font(.largeTitle)
                .padding()
                .background(Color.gray.opacity(0.2))
                .clipShape(Capsule())
        } icon:
        }
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
