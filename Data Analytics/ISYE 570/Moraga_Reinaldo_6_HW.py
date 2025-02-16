import rdatasets
import pandas as pd

csv_data = pd.read_csv(filepath_or_buffer='CollegeDistance.csv')

# Question 3
print("\nInformation about the data")
print(csv_data.info())

# Question 4
print("\nUnique values for column ethnicity, score, and education")
columns = ['ethnicity', 'score', 'education']
for i in csv_data.columns:
    print(i, csv_data[i].nunique())

# Question 6
print("\nMissing values per field")
print(csv_data.isna().sum(axis = 0))

# Question 7c
gender = ['male', 'female']
print("\nNumber of values for each unique value in column gender")
for x in gender:
    value = (csv_data['gender'] == x).sum()
    print(x, value)
columns = ['home', 'fcollege', 'mcollege']
answer = ['yes', 'no']
for x in columns:
    print("\nNumber of values for each unique value in column", x)
    for y in answer:
        value = (csv_data[x] == y).sum()
        print(y, value)
        
# Question 8
print("\nThe number of students grouped by fcollege and mcollege")
groups = csv_data.groupby(['fcollege', 'mcollege']).size()
print(groups)

print("\nThe average distance for each response to home")
distance_avg = csv_data.groupby(['home'])['distance'].mean()
print(distance_avg)

print("\nThe average tuition for each response to region and home")
tuition_avg = csv_data.groupby(['region', 'home'])['tuition'].mean()
print(tuition_avg)

print("\nThe average wage for each income level")
wage_avg = csv_data.groupby(['income'])['wage'].mean()
print(wage_avg)

# Question 9
print("\nNumber of students that live more than 12 miles from a 4-year college")
print("students:", (csv_data['distance'] > 12).sum())

print("\nNumber of students that live less than 12 miles from a 4-year college and have low income")
distance_comparison = csv_data['distance'] < 12
income_comparison = csv_data['income'] == 'low'
print("students:", len(csv_data[distance_comparison & income_comparison]))

print("\nNumber of students with both parents as college graduates and with high income")
fcollege_comp = csv_data['fcollege'] == 'yes'
mcollege_comp = csv_data['mcollege'] == 'yes'
income_comparison = csv_data['income'] == 'high'
print("students:", len(csv_data[fcollege_comp & mcollege_comp & income_comparison]))

# Extra Credit
print("\nAverage tuition for students where both parents went to college")
tuition_avg = csv_data[fcollege_comp & mcollege_comp]['tuition'].mean()
print(tuition_avg)