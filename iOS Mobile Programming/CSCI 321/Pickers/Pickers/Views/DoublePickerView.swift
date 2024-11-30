//
//  DoublePickerView.swift
//  Pickers
//
//  Created by Reinaldo Moraga on 2/24/22.
//

import SwiftUI

struct DoublePickerView: View {
    
    let pickerData = [
        ["Turkey", "Peanut Butter", "Tuna Salad", "Chicken Salad", "Salami", "Cheese", "Roast Beef"],
        ["Whole Wheat", "Rye", "Sourdough", "Seven Grain", "Italian"]
    ]
    
    let filling = 0
    let bread = 1
    
    @State private var fillingType = "Turkey"
    @State private var breadType = "Whole Wheat"
    @State private var showAlert = false
    
    var body: some View {
        GeometryReader { geometry in
            VStack {
                
                Text("Choose your Sandwich")
                    .font(.title)
                    .bold()
                    .multilineTextAlignment(.center)
                    .padding()
                
                HStack {
                    Picker("Filling Type", selection: $fillingType) {
                        ForEach(pickerData[filling], id: \.self) {
                            Text($0)
                        }
                    }
                    .pickerStyle(WheelPickerStyle())
                    .frame(width: geometry.size.width/2, alignment: .center)
                    .clipped()
                    
                    Picker("Bread Type", selection: $breadType) {
                        ForEach(pickerData[bread], id: \.self) {
                            Text($0)
                        }
                    }
                    .pickerStyle(WheelPickerStyle())
                    .frame(width: geometry.size.width/2, alignment: .center)
                    .clipped()
                }
                
                Button("Select") {
                    showAlert = true
                }
             
                Spacer()
            }
        }
        .alert(isPresented: $showAlert) {
            Alert(title: Text("Thank you for your order"),
                  message: Text("Your \(fillingType) on \(breadType) will be right up!"), dismissButton: .default(Text("Great!")))
        }
    }
}

struct DoublePickerView_Previews: PreviewProvider {
    static var previews: some View {
        DoublePickerView()
    }
}
