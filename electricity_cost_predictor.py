import numpy as np
from sklearn.linear_model import LinearRegression
import joblib

X = np.array([ #sample training data
    [30, 70, 220, 1.2],
    [32, 65, 225, 1.5],
    [29, 80, 218, 0.9],
    [35, 60, 230, 1.8],
    [33, 75, 210, 1.0],
    [28, 90, 215, 0.7]
])

y = np.array([5.2, 6.8, 4.5, 7.9, 5.0, 3.8]) # corresponding true outputs

model = LinearRegression()# model training
model.fit(X, y)

joblib.dump(model, "electricity_cost_model.pkl")# saving the model

test_sample = np.array([[31, 72, 222, 1.3]])  #testing the prediction, for a new input it gives a ŷ
predicted_cost = model.predict(test_sample)

print(f"Predicted cost: ₹{predicted_cost[0]:.2f}")
