//
//  ContentView.swift
//  AppStorageDemo
//
//  Created by Reinaldo Moraga on 3/10/22.
//

import SwiftUI

struct ContentView: View {
    
    @State private var red = 0.0
    @State private var green = 0.0
    @State private var blue = 0.0
    
    @AppStorage("redValue") var redValue = 0.0
    @AppStorage("greenValue") var greenValue = 0.0
    @AppStorage("blueValue") var blueValue = 0.0

    var body: some View {
        GeometryReader { geometry in
            VStack {
                
                Color(red: red, green: green, blue: blue, opacity: 1.0)
                    .frame(height: geometry.size.height * 0.4)
                    .cornerRadius(16)
                    .padding()
                
                HStack {
                    
                    VStack(alignment: .leading) {
                        Text("Red")
                            .font(.headline)
                            .padding()
                        Text("Green")
                            .font(.headline)
                            .padding()
                        Text("Blue")
                            .font(.headline)
                            .padding()
                    }
                    
                    VStack(alignment: .trailing, spacing: 30) {
                        Slider(value: $red, in: 0...1) { _ in
                            redValue = red
                        }
                        .padding(.horizontal)
                        
                        Slider(value: $green, in: 0...1) { _ in
                            greenValue = green
                        }
                        .padding(.horizontal)
                        
                        Slider(value: $blue, in: 0...1) { _ in
                            blueValue = blue
                        }
                        .padding(.horizontal)
                    }
                }
            }
            .onAppear {
                red = redValue
                green = greenValue
                blue = blueValue
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
