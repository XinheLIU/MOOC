# [Course Notes] How to Win a Data Science Competition-Learn from Top Kagglers

> Online Course from HSE

## Basic Elements of Competitive Data Science

### Data

- Numerical Features
- Preprocessing
  - Scale : min-max scaling, standard scaling (standardization)
  - Outliers : cliping, 
      - Ranking: 	a.	sets spaces between sorted values to be equal
      - transfomation
  - Tree-based models : does not depend on scaling, robust to missing & outliers
  - Non-tree-based models: hugely depend on scaling
- Feature generation 
    - Prior knowledge + EDA
- Missing values : hidden information 
    - Aviod filling in NaN before feature generation,
        - Some models (Tree, Xgboost) can handle NaN
    - Fill: Mean, median, -999, -1, reconstruct value (supervised/unsupervised learning)
    - Hidden missing values: can be already filled in dataset
- Model



http://blog.kaggle.com/2016/04/08/homesite-quote-conversion-winners-write-up-1st-place-kazanova-faron-clobber

- Model Evaluation (find a link)
* Accuracy 
* Logistic loss 
* AUC 
* RMSE 
* MAE 

Pandas tasks

- Numerical values
    - sklearn.preprocessing.MinMaxScaler
    - 
- Count and fill missing values (isnull, isna)




Platforms (compeitive DS) : find a book (红宝书）find community 和people

* Kaggle 
* DrivenData 
* CrowdAnalityx 
* CodaLab 
* DataScienceChallenge.net 
* Datascience.net 
* Single-competition sites (like KDD, VizDooM) 
