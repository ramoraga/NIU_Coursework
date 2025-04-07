import rdatasets
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
import statsmodels.api as sm
from sklearn.preprocessing import StandardScaler

df = pd.read_csv(filepath_or_buffer='winequality-white.csv', delimiter=";")

# Question 1a
print("\nNumber of observations:")
print(df.shape[0])

# Question 1c
print("\nNumber of missing values:")
print(df.isna().sum())

# Question 1d
print("\nNumber of observations for each quality level:")
quality_counts = df['quality'].value_counts().sort_index()
print(quality_counts)

# Question 2
features = ["chlorides", "density", "alcohol"]
X = df[features]
y = df["quality"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42, stratify=y)

log_model = LogisticRegression(multi_class='multinomial', solver='lbfgs', max_iter=5000)
log_model.fit(X_train, y_train)

y_pred = log_model.predict(X_test)

class_report = classification_report(y_test, y_pred, output_dict=True)

X_train_const = sm.add_constant(X_train)
logit_model = sm.MNLogit(y_train, X_train_const).fit()
p_values = logit_model.pvalues

for c in class_report:
    print(c,':',class_report[c])
print(p_values)

# Question 3a
X_a = df.drop(columns=["quality"])
y_a = df["quality"]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X_a)

X_train_a, X_test_a, y_train_a, y_test_a = train_test_split(
    X_scaled, y_a, test_size=0.25, random_state=42, stratify=y_a
)

log_model_a = LogisticRegression(multi_class="multinomial", solver="lbfgs", max_iter=5000)
log_model_a.fit(X_train_a, y_train_a)

y_pred_a = log_model_a.predict(X_test_a)
class_report_a = classification_report(y_test_a, y_pred_a, output_dict=True)

for c in class_report_a:
    print(c,':',class_report_a[c])

# Question 3b
df_b = df[df["quality"] != 9]

X_b = df_b.drop(columns=["quality"])
y_b = df_b["quality"]

X_scaled_b = scaler.fit_transform(X_b)

X_train_b, X_test_b, y_train_b, y_test_b = train_test_split(
    X_scaled_b, y_b, test_size=0.25, random_state=42, stratify=y_b
)

log_model_b = LogisticRegression(multi_class="multinomial", solver="lbfgs", max_iter=5000)
log_model_b.fit(X_train_b, y_train_b)

y_pred_b = log_model_b.predict(X_test_b)
class_report_b = classification_report(y_test_b, y_pred_b, output_dict=True)

for c in class_report_b:
    print(c,':',class_report_b[c])

# Question 3c
df_c = df[(df["quality"] != 3) & (df["quality"] != 9)]

X_c = df_c.drop(columns=["quality"])
y_c = df_c["quality"]

X_scaled_c = scaler.fit_transform(X_c)

X_train_c, X_test_c, y_train_c, y_test_c = train_test_split(
    X_scaled_c, y_c, test_size=0.25, random_state=42, stratify=y_c
)

log_model_c = LogisticRegression(multi_class="multinomial", solver="lbfgs", max_iter=5000)
log_model_c.fit(X_train_c, y_train_c)

y_pred_c = log_model_c.predict(X_test_c)
class_report_c = classification_report(y_test_c, y_pred_c, output_dict=True)

for c in class_report_c:
    print(c,':',class_report_c[c])