import rdatasets
import pandas as pd

this_data = rdatasets.data(package='Ecdat', item='DoctorContacts')

print("\noriginal columns: ", this_data.columns)
new_col = ['rownames', 'doctor visits', 'living conditions', 'insurance pay', 'long term physical illness', 'doctor experience', 
           'physical limitations', 'num of diseases', 'health status', 'lvl of income', 'fam size', 'educ lvl', 'age', 'sex',
           'kids', 'black']
this_data.columns = new_col

print("\nnew columns: ", this_data.columns)

print("\nInformation about the data")
print(this_data.info())

print("\nDescription of doctor visits column")
print(this_data['doctor visits'].describe())

print("\nDescription of age column")
print(this_data['age'].describe())

print("\nUnique values for every column")
for i in this_data:
    print(i, this_data[i].nunique())
    
print("\nMissing values in each column")
print(this_data.isna().sum(axis = 0))
    
print("\nMissing values in entire dataframe")
print(this_data.isna())

print("\nNumber of values for each unique value in column 'sex'")
num_males = (this_data['sex'] == 'male').sum()
num_females = (this_data['sex'] == 'female').sum()
print("males: ", num_males)
print("females: ", num_females)

print("\nNumber of patients with 'excellent' or 'good' health'")
excellent = (this_data['health status'] == 'excellent').sum()
good = (this_data['health status'] == 'good').sum()
num_patients = excellent + good
print("patients: ", num_patients)

print("\nNumber of patients below 18")
num_patients = (this_data['age'] < 18).sum()
print("patients: ", num_patients)
