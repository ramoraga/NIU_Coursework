//
//  DatePickerView.swift
//  Pickers
//
//  Created by Reinaldo Moraga on 2/24/22.
//

import SwiftUI

struct DatePickerView: View {
    
    @State private var selected = Date()
    @State private var showAlert = false
    

    var body: some View {
        VStack {
            Text("Choose a Date")
                .font(.title)
                .bold()
                .multilineTextAlignment(.center)
                .padding()
            
            DatePicker("Date", selection: $selected)
                .padding()
        
            Button("Select") {
                showAlert = true
            }
            .padding()
            
            Spacer()
        }
        .alert(isPresented: $showAlert) {
            Alert(title: Text("Date and Time Selected"),
                  message: Text("The date and time you have selected is \(selected)"))
        }
    }
}

struct DatePickerView_Previews: PreviewProvider {
    static var previews: some View {
        DatePickerView()
    }
}
