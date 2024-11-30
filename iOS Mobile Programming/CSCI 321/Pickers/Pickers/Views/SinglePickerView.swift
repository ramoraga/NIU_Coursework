//
//  SinglePickerView.swift
//  Pickers
//
//  Created by Reinaldo Moraga on 2/24/22.
//

import SwiftUI

struct SinglePickerView: View {
    
    let pickerData = ["Luke", "Leia", "Chewbacca", "R2-D2", "C-3PO", "Lando", "Rey", "Finn", "Grogu"]
    
    @State private var selected = "Luke"
    @State private var showAlert = false
    
    var body: some View {
        
        VStack {
            Text("Choose your Favorite Character")
                .font(.title)
                .bold()
                .multilineTextAlignment(.center)
                .padding()
            
            Picker("Favorite Character", selection: $selected) {
                ForEach(pickerData, id: \.self) {
                    Text($0)
                }
            }.pickerStyle(WheelPickerStyle())
            
            Button("Select") {
                showAlert = true
            }
            
            Spacer()
        }
        
        .alert(isPresented: $showAlert) {
            Alert(title: Text("You selected \(selected)"), message: Text("Thank you for choosing"), dismissButton: .default(Text("You're welcome")))
        }
    }
}

struct SinglePickerView_Previews: PreviewProvider {
    static var previews: some View {
        SinglePickerView()
    }
}
