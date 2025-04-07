import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder, StandardScaler
import tensorflow as tf
import matplotlib.pyplot as plt


df = pd.read_csv('Arthritis.csv', keep_default_na=False)
print(df.info())

# Question 1a
print("\nHow many missing values?")
print(df.isna().sum())

# Question 1b
print("\nWhich variables need to be encoded?")
for col in df.select_dtypes('object').columns:  
    print(f"Column {col}: {df[col].unique()}")

label_encoders = {}
for col in ['Treatment', 'Sex', 'Improved']:
    le = LabelEncoder()
    df[col] = le.fit_transform(df[col])
    label_encoders[col] = le

X = df[['Treatment', 'Sex', 'Age']]
y = df['Improved']

X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_val_scaled = scaler.transform(X_val)

# Question 2c
print("\n##### Model 1 #####")
model = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(X_train_scaled.shape[1],)),
    tf.keras.layers.Dense(3, activation='linear'),
    tf.keras.layers.Dense(3, activation='softmax')
])

model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(),
              metrics=['accuracy'])

history = model.fit(X_train_scaled, y_train, epochs=300, validation_data=(X_val_scaled, y_val))

results = pd.DataFrame(history.history)
print(results)

# Question 2d
print("\n##### Model 2 #####")
model_2 = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(X_train_scaled.shape[1],)),
    tf.keras.layers.Dense(8, activation='relu'),
    tf.keras.layers.Dense(4, activation='relu'),
    tf.keras.layers.Dense(3, activation='softmax'),
])

model_2.compile(optimizer='adam',
                loss=tf.keras.losses.SparseCategoricalCrossentropy(),
                metrics=['accuracy'])

history_2 = model_2.fit(X_train_scaled, y_train, epochs=500, validation_data=(X_val_scaled, y_val))

results2 = pd.DataFrame(history_2.history)
print(results2)

# Question 2e
plt.figure()
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.legend()
plt.title("Model 1 - Loss over Epochs")
plt.show()

plt.figure()
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.legend()
plt.title("Model 1 - Accuracy over Epochs")
plt.show()

plt.figure()
plt.plot(history_2.history['loss'], label='Training Loss')
plt.plot(history_2.history['val_loss'], label='Validation Loss')
plt.legend()
plt.title("Model 2 - Loss over Epochs")
plt.show()

plt.figure()
plt.plot(history_2.history['accuracy'], label='Training Accuracy')
plt.plot(history_2.history['val_accuracy'], label='Validation Accuracy')
plt.legend()
plt.title("Model 2 - Accuracy over Epochs")
plt.show()