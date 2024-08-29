import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
import seaborn as sns
import scipy.stats as st
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

data = pd.read_csv('Data.csv', usecols=['Date','Confirmed'])
print (data)
data_values =  data.values

k=0
for i in data_values:
    i[0]=str(k)
    k+=1
data_values = np.array(data_values,dtype=int)


X = data_values[:,0].reshape(-1,1)
Y = data_values[:,1].reshape(-1,1)
linear_regressor = LinearRegression()  # create object for the class
Regressaol = linear_regressor.fit(X, Y)  # perform linear regression
Y_pred = linearregressor.predict(X)  # make predictions

print("Valores:")
print("\tB0->" , Regressaol.intercept[0])
print("\tB1->", format(Regressaol.coef_[0][0], '.10f'))
print("\tE (squared)->", mean_squared_error(Y,Y_pred))
print("\tE (absolute)->", mean_absolute_error(Y,Y_pred))


plt.scatter(X, Y)
plt.plot(X, Y_pred, color='red')
plt.ylabel('Numero de casos ')
plt.xlabel('Dias')
plt.legend(['Numero de casos por dia'])
plt.title('Casos Covid 2021')
plt.grid()
plt.show()