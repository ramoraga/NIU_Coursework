//
//  ContentView.swift
//  DogCalculator
//
//  Created by Reinaldo Moraga & Rami Lake on 3/1/22.
//

import SwiftUI

struct ContentView: View {
    
    @StateObject private var viewModel = DogCalculatorViewModel()
    
    var body: some View {
        
        ZStack {
            
            // Gradient background
            LinearGradient(gradient: Gradient(colors: [Color(red: 3/255, green: 125/255, blue: 255/255), Color(red: 48/255, green: 199/255, blue: 108/255)]), startPoint: .top, endPoint: .bottom)
                .ignoresSafeArea()
            
            VStack {
                
                // Title w/ custom font
                Text("How Old is Your Dog?")
                    .font(.custom("Chicken Quiche", size: 32))
                    .foregroundColor(.white)
                    .padding()
                                
                // User input field for dog's age
                TextField("Enter your dog's age", text: $viewModel.dogAgeText)
                    .keyboardType(.numbersAndPunctuation)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                    .padding()
                
                // Image for dog
                Image("dog")
                    .resizable()
                    .clipShape(Circle())
                    .frame(width: 200, height: 200, alignment: .leading)
                    .scaledToFit()
                    .padding()
                
                // Button that converts dog years to human years
                // Calls the function compute() from viewModel
                Button(action: { viewModel.compute() },
                       label: {
                        Text("Human Age")
                            .font(.title3)
                            .bold()
                            .foregroundColor(Color(red: 48/255, green: 199/255, blue: 108/255))
                            .padding()
                            .background(Capsule()  .foregroundColor(.white))
                            .padding()
                })
                
                // Output for the conversion results
                Text(viewModel.resultMessage)
                    .font(.title3)
                    .bold()
                    .foregroundColor(.white)
                    .padding()

                Spacer()
               
            }
            //Alert for when user doesn't enter a number
            .alert(isPresented: $viewModel.showAlert) {
                Alert(
                    title: Text("Error"),
                    message: Text(viewModel.errorMessage)
                )
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
