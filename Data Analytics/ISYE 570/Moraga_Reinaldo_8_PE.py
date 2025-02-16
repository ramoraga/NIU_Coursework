import rdatasets
import scipy.stats as sp
import pandas as pd

data = rdatasets.data(package='Ecdat', item='Computers')

# Question 2
print("\nMissing values per field")
print(data.isnull().sum(axis = 0))

# Question 3
print("\nInformation about the data")
print(data.info())

# Question 4
print("\nCardinality for every column")
for i in data.columns:
    print(f"{i}: {data[i].nunique()}")
    
# Question 6
print("\nNumber of observations for each unique value of the columsn with cardinality < 10")
for i in data.columns:
    if data[i].nunique() < 10:
        print(f"{data[i].value_counts()}\n")
        
# Question 7
print("\nPearson correlation between all numeric variables")      
columns = ['price', 'speed', 'hd', 'ram', 'screen', 'ads', 'trend']        
correlation_data = []

for i in range(0, len(columns) - 1):
    for j in range(i + 1, len(columns)):
        result = sp.pearsonr(data[columns[i]], data[columns[j]])
        correlation_data.append({'X': columns[i], 'Y': columns[j], 'Correlation': result.statistic, 'P-value': result.pvalue})
                
correlation_df = pd.DataFrame(correlation_data)
print(correlation_df)

# Question 8
print("\nChi Squared Test of Independence")
cont_table = pd.crosstab(data['cd'], data['premium'])
chi2_result = sp.chi2_contingency(cont_table)
print(f"Between cd and premium\nP-Value: {chi2_result.pvalue}\nDOF: {chi2_result.dof}\nExpected Freq: {chi2_result.expected_freq}\n")

cont_table = pd.crosstab(data['speed'], data['premium'])
chi2_result = sp.chi2_contingency(cont_table)
print(f"Between speed and premium\nP-Value: {chi2_result.pvalue}\nDOF: {chi2_result.dof}\nExpected Freq: {chi2_result.expected_freq}\n")

cont_table = pd.crosstab(data['speed'], data['multi'])
chi2_result = sp.chi2_contingency(cont_table)
print(f"Between speed and multi\nP-Value: {chi2_result.pvalue}\nDOF: {chi2_result.dof}\nExpected Freq: {chi2_result.expected_freq}\n")