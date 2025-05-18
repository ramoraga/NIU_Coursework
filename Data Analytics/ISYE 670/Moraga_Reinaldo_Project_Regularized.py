import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score

df = pd.read_csv("data.csv", sep=';')

df.columns = [col.strip().replace('\t', '') for col in df.columns]
print(df.info(), "\n")

print("Target Distribution:\n", df['Target'].value_counts())
df['Target'] = df['Target'].map({'Dropout': 0, 'Enrolled': 1, 'Graduate': 2})

df.dropna(inplace=True)

X = df.drop("Target", axis=1)
y = df["Target"]

numeric_cols = X.select_dtypes(include=['int64', 'float64']).columns

scaler = StandardScaler()
X_scaled = X.copy()
X_scaled[numeric_cols] = scaler.fit_transform(X[numeric_cols])

X_train, X_test, y_train, y_test = train_test_split(
    X_scaled, y, test_size=0.2, random_state=42, stratify=y
)

print("\nTraining set size:", X_train.shape)
print("Test set size:", X_test.shape)

# Logistic Regression
# Logistic Regression with L2 regularization (Ridge)
log_reg = LogisticRegression(penalty='l2', C=1.0, max_iter=1000, random_state=42)
log_reg.fit(X_train, y_train)
y_pred_log = log_reg.predict(X_test)

# Random Forest
# Random Forest with regularization-like constraints (max_depth and min_samples_split)
rf = RandomForestClassifier(max_depth=10, min_samples_split=5, random_state=42)
rf.fit(X_train, y_train)
y_pred_rf = rf.predict(X_test)

print("\nLogistic Regression Results:\n", classification_report(y_test, y_pred_log))
print("Random Forest Results:\n", classification_report(y_test, y_pred_rf))

# Cross Validation
log_reg = LogisticRegression(penalty='l2', C=1.0, max_iter=5000, random_state=42)
# Random Forest with regularization-like constraints (max_depth and min_samples_split)
rf = RandomForestClassifier(max_depth=10, min_samples_split=5, random_state=42)

scores_log = cross_val_score(log_reg, X_train, y_train, cv=5)
scores_rf = cross_val_score(rf, X_train, y_train, cv=5)

print(f"Logistic Regression CV Accuracy: {scores_log.mean():.3f} ± {scores_log.std():.3f}")
print(f"Random Forest CV Accuracy: {scores_rf.mean():.3f} ± {scores_rf.std():.3f}")

