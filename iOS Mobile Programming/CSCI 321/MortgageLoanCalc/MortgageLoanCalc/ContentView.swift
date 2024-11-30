//
//  ContentView.swift
//  MortgageLoanCalc
//
//  Created by Reinaldo Moraga & Rami Lake on 3/28/22.
//

import SwiftUI

struct ContentView: View {
    
    // Declare variables
    @State private var loanText = ""
    @State private var rate = 0.01
    @State private var year = 10.00
    @State private var errorMessage = ""
    @State private var showAlert = false
    @State private var formatCalc = "0"
    
    
    var body: some View {
        
        VStack {
            
            // Title
            Text("Loan Calculator")
                .font(.title)
                .bold()
            
            // User input field for mortgage loan
            TextField("Enter a mortgage loan principal", text: $loanText)
                .keyboardType(.numbersAndPunctuation)
                .textFieldStyle(RoundedBorderTextFieldStyle())
                .padding()
            
            // UI Control used to increase or decrease annual interest rate
            Stepper(value: $rate, in:
                        0.01...20.00, step: 0.01) {
                Text("Interest")
                    .bold()
            }
            .padding(.horizontal)
            
            // Display for current annual rate
            HStack {
                Text("Annual Rate")
                    .bold()
                    .padding(.horizontal)
                
                Spacer()
                
                let formatRate = String(format: "%.2f", rate)
                Text("\(formatRate)%")
                    .padding(.horizontal)
            }
            .padding(.vertical)
            
            // Display for current number of years
            HStack {
                Text("Number of Years")
                    .bold()
                    .padding(.horizontal)
                
                Spacer()
                
                let formatYear = String(format: "%.f", year)
                Text("\(formatYear)")
                    .padding(.horizontal)
            }
            .padding(.bottom)
            
            // UI Control used to increase or decrease number of years
            Slider(value: $year, in: 10...30, step: 5, minimumValueLabel: Text("10"), maximumValueLabel: Text("30"), label: {
                Text("Number of Years")
                    .bold()
                    .font(.title3)
            })
                .padding(.horizontal)
            
            // Button that calculates monthly payment
            Button(action: { compute() }, label: {
                Text("Calculate")
                    .font(.headline)
                    .bold()
                    .foregroundColor(.white)
                    .padding()
                    .background(Capsule()
                        .foregroundColor(.black))
                    .padding()
            })
            
            // Display for calculated monthly payment
            HStack {
                Text("Monthly Payment")
                    .bold()
                    .padding(.horizontal)
                
                Spacer()
                
                Text("$\(formatCalc)")
                    .padding(.horizontal)
            }
            .padding(.bottom)
            
        }
        // Alert for user input isn't a number
        .alert(isPresented: $showAlert) {
            Alert(title: Text("Error"),
                  message:
                    Text(errorMessage)
            )
        }
    }
        
    func compute() {
        
        // Convert user input string to a double
        // If input can't be converted to double, display error message
        guard let loan = Double(loanText) else {
            errorMessage = "Please enter a valid number for your mortgage loan!"
            showAlert = true
            return
        }
            
        // Declare variables
        var monthlyPayment: Double
        var monthlyRate: Double
        var numOfPayments: Double
        var numerator: Double
        var denominator: Double
        
        // Calculate monthly interest rate, and total number of payments
        monthlyRate = (rate / 100) / 12
        numOfPayments = year * 12
        
        // Calculate monthly payments
        numerator = loan * monthlyRate * pow(1 + monthlyRate, numOfPayments)
        denominator = pow(1 + monthlyRate, numOfPayments) - 1
        monthlyPayment = numerator / denominator
        
        // Format calculated number
        let numberFormatter = NumberFormatter()
        numberFormatter.numberStyle = .decimal
        numberFormatter.maximumFractionDigits = 2
        
        formatCalc = numberFormatter.string(from: NSNumber(value: monthlyPayment))!
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
