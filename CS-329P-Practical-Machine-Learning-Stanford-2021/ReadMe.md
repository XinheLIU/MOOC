# Practical Machine Learning Course Notes

> [Course Webpage](https://c.d2l.ai/stanford-cs329p)

- [Practical Machine Learning Course Notes](#practical-machine-learning-course-notes)
  - [Data](#data)
    - [Overview](#overview)
    - [Data Collection](#data-collection)
      - [Common ML Data Sets](#common-ml-data-sets)
      - [DataSet Sources](#dataset-sources)
      - [Discover or Integrate Data](#discover-or-integrate-data)
    - [Data Labeling](#data-labeling)
    - [Data Transformation](#data-transformation)
    - [Feature Engineering](#feature-engineering)
  - [2 Data Analysis](#2-data-analysis)
  - [3 Machine Learning Models](#3-machine-learning-models)

## Data

### Overview

ML Applications

- Manufacturing
  - Predictive maintenance, quality control  
- Retail
  - Recommendation, chatbot, demand forecasting
- Healthcare
  - Alerts from real-time patient data, disease identification
- Finance
  - Fraud detection, application processing
- Automobile
  - Breakdown prediction, self-driving

Challenges

- Formulate problem: focus on the most impactful industrial problems
- **Data**: high-quality data is scarce, **privacy issues**
- Train models: ML models are more and more complex, data-hungry, expensive
- **Deploy models**: heavy computation is not suitable for real-time inference
- **Monitor**: data distributions shifts, fairness issues

### Data Collection

- Raw data is most flexible, (arguablly) most valuable, but needs lot of effort to process

#### Common ML Data Sets

- MNIST: digits written by employees of the US Census Bureau • ImageNet: millions of images from image search engines
- AudioSet: YouTube sound clips for sound classification
- LibriSpeech: 1000 hours of English speech from audiobook
- Kinetics: YouTube videos clips for human actions classification
- KITTI: traffic scenarios recorded by cameras and other sensors
- Amazon Review: customer reviews and from Amazon online shopping • SQuAD: question-answer pairs derived from Wikipedia

#### DataSet Sources

- [Paperswithcodes Datasets](https://paperswithcode.com/datasets): academic datasets with leaderboard
- [Kaggle Datasets](https://www.kaggle.com/datasets): ML datasets uploaded by data scientists
- [Google Dataset search](https://datasetsearch.research.google.com/): search datasets in the Web
- Various toolkits datasets: [tensorflow](https://www.tensorflow.org/datasets), [huggingface](https://huggingface.co/docs/datasets/)
- Various conference/company ML competitions
- [Open Data on AWS](https://registry.opendata.aws/): 100+ large-scale raw data
- Data lakes in your own organization

#### Discover or Integrate Data

- Synthetic Data: GANs, Simulation, Data Augmentations
- Web Scrapping
  - Crawling:indexing whole pages on Internet
  - Scraping:scraping particular data from webpages of a website
  - You need a lot of new IPs, easy to get through public clouds
    - AWS, AZure, GCP

### Data Labeling

> Example: Tesla

- Semi-Supervised Learning
  - Focus on the scenario where there is a small amount of labeled data, along with large amount of unlabeled data
  - Assmptions
    - Continuity assumptions
    - Cluster assumption
    - Manifold assumption
  - Self-Training Process : Only **keep highly confident labels**.
- Label by Crowd Sourcing
  - use online models
  - Corwd Source by paying users
    - Challenges
      - Simplify user interaction: design easy tasks, clear instructions and simple to use interface
      - Labelers make mistakes (honest or not) and may fail to understand the instructions
  - **Active Learning**
    - Model select the most“interesting” data for labelers
    - Uncertainty sampling
      - Select examples whose predictions are most uncertain, The highest class prediction score is close to random(1/n)
      - Can be combined with semi-supervised learning
    - Query-by-committee: Train smultiple models and select samples that models disagree with
- Data programming
  - Domain specific heuristics to assign labels
  - Keyword search,pattern matching,third-partymodels

### Data Transformation


### Feature Engineering


## 2 Data Analysis

- 2.1 EDA
  - 注意数据大小
  - 常用包 可以读zip
  - Regex 重要性
  - 阅读李沐那个notebook；到底想干嘛
- 2.2 cleasing
  - 关于数据库基本知识
  - 洗数据工具 plotly做
  - 交互式数据清洗工具：（找找研究工作）
- 2.3 data transformation
  - Document import methods : 各种数据自己需要check的 transform的（checklist）
  - tokenization，alterantive data etc
- 2.4 feature engineering
  - Tabluar data learning
  - 在字节的经验使用
- 2.5 daily life
  - Data quality (very important)
  - Unbiased & causal learnings
    - Diversity
    - Unbiased
    - Fairness
  - Large scale data management: storage, porocess, version security

## 3 Machine Learning Models

- 3.1 ML Model overview
  - RL 思路，比较难，和环境交互比较难控制
  - surpervised主流
  -
- 3.2 Tree Models
  - GBDT & ResNet
  - use tree first
- 3.3 Linear Models
  - softmax classifier (原理)
- 3.4 Graident Descent
  - mini-batch stochastic gradient descent (batch size and learning rate needs to be chosen)
- 3.5 Neural Networks: Multilayer Perceptron
  - 训练需要大量数据做随机梯度下降
  - Activation function choice : sigmoid, Relu
  - dense layer
  - hidden layer: not visible when you check outputs
  - hyper parameters: num_hiddens, num_inputs
- 3.6 Convolution Neural Network
  - prior knowledge for futire extraction
  - translation invariqnce *
  - licality *

-
3.6 Convolution Neural Network

- Review Code of Pytorch
- 复习卷积神经网络的输入输入维度估算
- 深度理解原理：其他场景下应用
- 下载PPT：
- Design Patterns of Neural Networks （产品经理的架构能力）
- 动手机器学习
3.7 Recurrent Networks
- Language Model
- RNN
- LSTM， GRU：remember & forget 底层原理
- bidirectional and deep  
- tabnet transformations 多了解多读paper

5.1 Bias and Variance

- Bias and variance decomposition
- How to test bias and variance
  - Sigma: from your data **
- How to reduce bias and variance : mark
5.2 Bagging
- Out of bag : 1/3 data
5.3 boosting
- AdaBoost 自己了解 非常经典
- Gradient Boosting : train on residuals
- shrinkage
- Weak learners (what are the weak learners)
5.4 Stacking
- 刷榜神器
- autoglun
- Repeated K-fold bagging (**)

9.1 模型调参

- 从一些手动default包开始
- 模型对于hyper parameter 敏感性 不同 eg 对于Adam 对于学习率敏感区间宽
- experiment managent is very hard
  - Tenosrboard & weight & bias
- 实验可重复性比较难
  - Code
    - hardware
    - Libary: Python库backward compatibility not super good
  - randomness
  - 拓展：实验平台
- Automated hyper parameter training : very hard

datediff(from_unixtime(unix_timestamp('${date}','yyyymmdd'),'yyyy-mm-dd'), to_date(ad_create_date))
