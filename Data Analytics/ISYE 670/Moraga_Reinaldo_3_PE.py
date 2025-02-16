import rdatasets
import pandas as pd
from sklearn.preprocessing import OrdinalEncoder
from sklearn.model_selection import train_test_split
import statsmodels.api as sm
from sklearn.metrics import accuracy_score, confusion_matrix

csv_data = pd.read_csv(filepath_or_buffer='bank.csv', delimiter=";")

# Question 1
print("\nInformation about the data")
print(csv_data.info())

# Question 2
print("\nMissing values per field")
print(csv_data.isna().sum())

# Question 3
print("\nPotential missing values")
missing = {}
values = ["unknown", "?", "none", "N/A", "null", ""]

for column in csv_data.columns:
    unique = csv_data[column].astype(str).str.lower().unique()
    i = [v for v in unique if v in values]
    if i:
        missing[column] = i

print(missing,"\n")

csv_clean = csv_data.dropna()
categorical_cols = csv_clean.select_dtypes(include=['object']).columns
encoder = OrdinalEncoder()
csv_clean[categorical_cols] = encoder.fit_transform(csv_clean[categorical_cols])

train_data, test_data = train_test_split(csv_clean, test_size=0.25)
X_train = train_data.drop(columns=["y"])
y_train = train_data["y"].astype(int)

X_train = sm.add_constant(X_train)

print("===== Model 1 =====")
model = sm.Logit(y_train, X_train)
result = model.fit()
print(result.summary())

# a
significant_vars = result.pvalues[result.pvalues < 0.05].index.tolist()

# b
pseudo_r_squared = result.prsquared

# c
X_test = test_data.drop(columns=["y"])
y_test = test_data["y"].astype(int)

X_test = sm.add_constant(X_test)

y_pred_prob = result.predict(X_test)
y_pred = (y_pred_prob >= 0.5).astype(int)

accuracy = accuracy_score(y_test, y_pred)

# d
tneg, fpos, fneg, tpos = confusion_matrix(y_test, y_pred).ravel()

print(significant_vars, "\n", pseudo_r_squared, accuracy, fpos, fneg)

print("===== Model 2 =====")

# a
insignificant_vars = result.pvalues[result.pvalues >= 0.05].index.tolist()
insignificant_vars.remove("const") if "const" in insignificant_vars else None

# b
X_train_reduced = X_train.drop(columns=insignificant_vars)
reduced_model = sm.Logit(y_train, X_train_reduced)
reduced_result = reduced_model.fit()

X_test = test_data.drop(columns=["y"])
y_test = test_data["y"].astype(int)

X_test = sm.add_constant(X_test)
X_test_reduced = X_test.drop(columns=insignificant_vars)

y_pred_prob_reduced = reduced_result.predict(X_test_reduced)
y_pred_reduced = (y_pred_prob_reduced >= 0.5).astype(int)

accuracy_reduced = accuracy_score(y_test, y_pred_reduced)

# c
tn_reduced, fp_reduced, fn_reduced, tp_reduced = confusion_matrix(y_test, y_pred_reduced).ravel()

# d
aic_full, bic_full = result.aic, result.bic
aic_reduced, bic_reduced = reduced_result.aic, reduced_result.bic

print(insignificant_vars, "\n", accuracy_reduced, fp_reduced, fn_reduced, "\n", (aic_full, bic_full), (aic_reduced, bic_reduced))
