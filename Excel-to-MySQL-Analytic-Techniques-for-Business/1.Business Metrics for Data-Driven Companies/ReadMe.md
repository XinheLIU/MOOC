# Business Metrics for Data Driven Company

- [Business Metrics for Data Driven Company](#business-metrics-for-data-driven-company)
  - [Week 1: Recognize the most critical business metrics and distinguish them from mere data](#week-1-recognize-the-most-critical-business-metrics-and-distinguish-them-from-mere-data)
    - [data analyst’s value](#data-analysts-value)
    - [business metrics](#business-metrics)
      - [Dynamic Metrics](#dynamic-metrics)
    - [Case Study: Amazon](#case-study-amazon)
  - [Week 2: Analyze the different roles Business Analysts, Business Data Analysts, and Data Scientists play in various types of companies](#week-2-analyze-the-different-roles-business-analysts-business-data-analysts-and-data-scientists-play-in-various-types-of-companies)
  - [Week 3: Describe the skills required to be hired for, and succeed at, these high-demand jobs](#week-3-describe-the-skills-required-to-be-hired-for-and-succeed-at-these-high-demand-jobs)
  - [Week 4: Define the different data-related roles needed in a company in order to implement and make use of data analysis.](#week-4-define-the-different-data-related-roles-needed-in-a-company-in-order-to-implement-and-make-use-of-data-analysis)

## Week 1: Recognize the most critical business metrics and distinguish them from mere data

### data analyst’s value

- find the right question to ask
  - computerized response
  - [Just In Time JIT](https://www.investopedia.com/terms/j/jit.asp)
  - recommendations for decision making
    - AB Testing
- ensure your answer has practical impact
- translate to specific call to action

### business metrics

- Revenue metrics 
  - relate to sales and marketing. 
  - enterprise sales (toB metrics)
  - sales funnel
    - new leads
    - new qualified leads:
      - identify decision maker
      - expression of interest
    - soft circle sales
  - dynamic revenue metrics
    - recommendation system
- Profitability metrics 
  - to efficiency and logistics, production, and operations. 
  - inventory management
    - negative floats requires working capital
    - storage cost
    - wastage
    - obsolescence 
      - The company's inventory on hand at the end of the year divided by the total annual cost of goods sold and then multiplied by 365 for days of the year is a very good estimate of average days inventory.
    - retail dynamic metrics: track inventory turnaround and days inventory at the individual product SKU level.
    - hotel & airline
      - occupancy rate
      - holidays, promotions & sales
      - Over opaque inventory pricing, OTA's
- Risk metrics 
  - to risk management, and are widely used by a company's creditors, and outside investors.
  - churn rate
  - cash flows
  - leverage
  - reputation, operational risk

#### Dynamic Metrics

Two attributes make a business metric dynamic.

- First, will the metric change significantly over intervals of a month or less? If not, it's not very dynamic. 
- How much impact a business change can have on the metric, is another important thing that we need to observe.
  - Small changes in process, in our process, can lead to big impact.

### Case Study: Amazon

The beauty of Amazon's underlying computer system design is evident in how seamlessly what the user sees combines a large amount of pre-processed data from various databases and indexes, with real-time responses to the user's query, their clicking activity, they're all-important clickstream. Real-time customization means that a company can customize each individual's user experience while that user's session is going on in real time, based on that user's historical and clickstream data, informed by detailed records of what that visitor and similar visitors did in the past.

- The high level subject index also expands to include subtopics. If I click on AI and Machine Learning,
- The second step involves identifying the best-selling books within the subject subcategories my search terms fit best.
  
What have we discovered about the Amazon database behind this individualized magic? We already know that for every unique book ID, Amazon must store a tree of subject area categories and subtopics, subcategories, that the book is located in, and a record of how each book ranks in terms of Amazon's own recent sales within each of the subject area categories and subcategories in which it is cross-listed. We are about to see what other dynamic revenue metrics Amazon tracks for each book, and how it stores and uses that information

Amazon maintains a co-occurrence database of every book that a web user clicked on while browsing. Wow, that is a lot of detail. Clickstream data about everything I ever looked at but did not buy

How do I know that Amazon does this? Because, at the bottom of the same page is a separate co-occurrence list of the books people most commonly bought during the same session when they viewed the MacKay textbook without buying it. So we know that Amazon is maintaining a co-occurrence matrix that lists for every visit that results in the sale of at least one book to other possibilities. First, when book one is bought, it has a list of all other books bought. And second, when book one is bought, it has a list of all other books viewed. By using this second set of records, Amazon can identify what books were ultimately purchased by people who viewed but did not buy any given book. So, to summarize, Amazon's first line of promotion is the profit maximizing frequently bought together metric. Their second metric is a kind of recommendation engine.

## Week 2: Analyze the different roles Business Analysts, Business Data Analysts, and Data Scientists play in various types of companies

## Week 3: Describe the skills required to be hired for, and succeed at, these high-demand jobs

## Week 4: Define the different data-related roles needed in a company in order to implement and make use of data analysis. 