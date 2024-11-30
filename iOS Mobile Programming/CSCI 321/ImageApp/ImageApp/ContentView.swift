//
//  ContentView.swift
//  ImageApp
//
//  Created by Reinaldo Moraga on 2/10/22.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack(spacing: 20) {
            ZStack {
            Image("Bliss_(Windows_XP)")
                .resizable()
                .clipShape(Circle())
                .frame(width: 200, height: 200)
                
                Text("WINDOWS XP")
                    .foregroundColor(.red)
                    .bold()
                    .font(.largeTitle)
            }
            
            Image(systemName: "calendar.circle.fill")
                .imageScale(.large)
                .foregroundColor(.mint)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
