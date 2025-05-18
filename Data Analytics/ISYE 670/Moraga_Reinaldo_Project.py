import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

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
log_reg = LogisticRegression(max_iter=1000, random_state=42)
log_reg.fit(X_train, y_train)
y_pred_log = log_reg.predict(X_test)

# Random Forest
rf = RandomForestClassifier(random_state=42)
rf.fit(X_train, y_train)
y_pred_rf = rf.predict(X_test)

print("\nLogistic Regression Results:\n", classification_report(y_test, y_pred_log))
print("Random Forest Results:\n", classification_report(y_test, y_pred_rf))

# Cross Validation
log_reg = LogisticRegression(max_iter=5000, random_state=42)
rf = RandomForestClassifier(random_state=42)

scores_log = cross_val_score(log_reg, X_train, y_train, cv=5)
scores_rf = cross_val_score(rf, X_train, y_train, cv=5)

print(f"Logistic Regression CV Accuracy: {scores_log.mean():.3f} ± {scores_log.std():.3f}")
print(f"Random Forest CV Accuracy: {scores_rf.mean():.3f} ± {scores_rf.std():.3f}")

# Logistic Regression with regularization
log_reg = LogisticRegression(penalty='l2', C=1.0, max_iter=1000, random_state=42)
log_reg.fit(X_train, y_train)
y_pred_log = log_reg.predict(X_test)

# Random Forest with regularization
rf = RandomForestClassifier(max_depth=10, min_samples_split=5, random_state=42)
rf.fit(X_train, y_train)
y_pred_rf = rf.predict(X_test)

print("##### Regularization #####")
print("\nLogistic Regression Results:\n", classification_report(y_test, y_pred_log))
print("Random Forest Results:\n", classification_report(y_test, y_pred_rf))

# Cross Validation
log_reg = LogisticRegression(penalty='l2', C=1.0, max_iter=5000, random_state=42)
rf = RandomForestClassifier(max_depth=10, min_samples_split=5, random_state=42)

scores_log = cross_val_score(log_reg, X_train, y_train, cv=5)
scores_rf = cross_val_score(rf, X_train, y_train, cv=5)

print(f"Logistic Regression CV Accuracy: {scores_log.mean():.3f} ± {scores_log.std():.3f}")
print(f"Random Forest CV Accuracy: {scores_rf.mean():.3f} ± {scores_rf.std():.3f}")

# Confusion Matrices
fig, axes = plt.subplots(1, 2, figsize=(14, 5))
for ax, model_name, y_pred in zip(axes, ['Logistic Regression', 'Random Forest'], [y_pred_log, y_pred_rf]):
    cm = confusion_matrix(y_test, y_pred)
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', ax=ax, cbar=False)
    ax.set_title(f'{model_name} Confusion Matrix')
    ax.set_xlabel('Predicted')
    ax.set_ylabel('Actual')

plt.tight_layout()
plt.show()

# Box Plot: Cross-Validation Accuracy
cv_scores = {
    'Logistic Regression': cross_val_score(log_reg, X_train, y_train, cv=5),
    'Random Forest': cross_val_score(rf, X_train, y_train, cv=5)
}

cv_df = pd.DataFrame({
    'Accuracy': np.concatenate([cv_scores['Logistic Regression'], cv_scores['Random Forest']]),
    'Model': ['Logistic Regression'] * 5 + ['Random Forest'] * 5
})

plt.figure(figsize=(7, 5))
sns.boxplot(x='Model', y='Accuracy', data=cv_df)
plt.title("Cross-Validation Accuracy Comparison")
plt.grid(True)
plt.show()

# Bar Plot: Precision, Recall, F1-score
def extract_class_report(y_true, y_pred, model_name):
    report = classification_report(y_true, y_pred, output_dict=True)
    df_report = pd.DataFrame(report).transpose()
    df_report = df_report.loc[['0', '1', '2'], ['precision', 'recall', 'f1-score']]
    df_report['Model'] = model_name
    df_report['Class'] = ['Dropout', 'Enrolled', 'Graduate']
    return df_report

log_df = extract_class_report(y_test, y_pred_log, 'Logistic Regression')
rf_df = extract_class_report(y_test, y_pred_rf, 'Random Forest')
report_df = pd.concat([log_df, rf_df])

# Plot precision/recall/f1
melted = report_df.melt(id_vars=['Model', 'Class'], var_name='Metric', value_name='Score')
plt.figure(figsize=(10, 6))
sns.barplot(data=melted, x='Class', y='Score', hue='Model', ci=None, palette='Set2', dodge=True)
plt.title("Precision / Recall / F1-Score by Class")
plt.ylim(0, 1)
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
plt.grid(True)
plt.tight_layout()
plt.show()
