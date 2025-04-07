import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report
from sklearn.feature_selection import RFECV
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LogisticRegression
from scipy.stats import ttest_ind

df = pd.read_csv('winequality-white.csv', delimiter=";")

# Question 1
X = df[['chlorides', 'density', 'alcohol']]
y = df['quality']

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

model_a = SVC()
model_a.fit(X_train, y_train)

y_pred = model_a.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
report = classification_report(y_test, y_pred, output_dict=True)

print("################ Model 1 ################")
print(f"Accuracy: {accuracy * 100:.2f}%")
print("Classification Report:")
for label, metrics in report.items():
    if label not in ['accuracy', 'macro avg', 'weighted avg']:
        print(f"Class {label}: Precision={metrics['precision']:.2f}, Recall={metrics['recall']:.2f}, F1-Score={metrics['f1-score']:.2f}")

# Question 2
X_full = df.drop(columns=['quality'])
y_full = df['quality']

svm = SVC(kernel='linear')
pipeline = Pipeline([
    ('scaler', StandardScaler()),
    ('feature_selection', RFECV(estimator=svm, step=1, cv=5, scoring='accuracy'))
])
pipeline.fit(X_full, y_full)

selected_mask = pipeline.named_steps['feature_selection'].support_
selected_features = X_full.columns[selected_mask].tolist()

X_selected = df[selected_features]
y = df['quality']

X_train_b, X_test_b, y_train_b, y_test_b = train_test_split(
    X_selected, y, test_size=0.25, random_state=42, stratify=y
)

pipeline_b = Pipeline([
    ('scaler', StandardScaler()),
    ('svm', SVC()) 
])
pipeline_b.fit(X_train_b, y_train_b)

y_pred_b = pipeline_b.predict(X_test_b)
accuracy_b = accuracy_score(y_test_b, y_pred_b)
report_b = classification_report(y_test_b, y_pred_b, output_dict=True)

print("\n################ Model 2 ################")
print("Selected Features:", selected_features)
print(f"Accuracy: {accuracy_b * 100:.2f}%")
print("Classification Report:")
for label, metrics in report_b.items():
    if label not in ['accuracy', 'macro avg', 'weighted avg']:
        print(f"Class {label}: Precision={metrics['precision']:.2f}, Recall={metrics['recall']:.2f}, F1-Score={metrics['f1-score']:.2f}")

# Question 3
X = df[selected_features]
y = df['quality']

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

pipeline_svm = Pipeline([
    ('scaler', StandardScaler()),
    ('svm', SVC())
])
pipeline_svm.fit(X_train, y_train)
y_pred_svm = pipeline_svm.predict(X_test)
accuracy_svm = accuracy_score(y_test, y_pred_svm)
report_svm = classification_report(y_test, y_pred_svm, output_dict=True)

pipeline_logreg = Pipeline([
    ('scaler', StandardScaler()),
    ('logreg', LogisticRegression(max_iter=1000))
])
pipeline_logreg.fit(X_train, y_train)
y_pred_logreg = pipeline_logreg.predict(X_test)
accuracy_logreg = accuracy_score(y_test, y_pred_logreg)
report_logreg = classification_report(y_test, y_pred_logreg, output_dict=True)

class_labels = sorted(set(y_test))
svm_f1_scores = [report_svm[str(label)]['f1-score'] for label in class_labels if str(label) in report_svm]
logreg_f1_scores = [report_logreg[str(label)]['f1-score'] for label in class_labels if str(label) in report_logreg]

t_stat, p_val = ttest_ind(svm_f1_scores, logreg_f1_scores, equal_var=False)

print("\n################ Question 3 ################")
print(f"Model B (SVM) Accuracy: {accuracy_svm:.4f}")
print(f"Logistic Regression Accuracy: {accuracy_logreg:.4f}")
print(f"\nT-test on F1 scores:\nT-statistic: {t_stat:.4f}, P-value: {p_val:.4f}")

print("\nSVM F1-Scores by Class:")
for label in class_labels:
    if str(label) in report_svm:
        f1 = report_svm[str(label)]['f1-score']
        print(f"  Class {label}: F1 = {f1:.2f}")

print("\nLogistic Regression F1-Scores by Class:")
for label in class_labels:
    if str(label) in report_logreg:
        f1 = report_logreg[str(label)]['f1-score']
        print(f"  Class {label}: F1 = {f1:.2f}")