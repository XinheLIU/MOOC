


Checklist for EDA

1. Formulate your question
2. Read in your data
3. Check the packaging
4. Runstr()
5. Look at the top and the bottom of your data
6. Check your “n”s
7. Validate with at least one external data source
8. Try the easy solution first
9. Challenge your solution
10. Follow up
    1.  Do you have the right data?
    2.  Do you need other data?
    3.  Do you have right question?

Read Data/Data Clearning

Sometimes the data will come in a very messy format and you’ll need to do some cleaning. Other times, someone else will have cleaned up that data for you so you’ll be spared the pain of having to do the cleaning.


The readr package by Hadley Wickham is a nice package for reading in flat files very fast, or at least much faster than R’s built-in functions. It makes some tradeoffs to obtain that speed, so these functions are not always appropriate, but they serve our purposes here.

run str() on the dataset. This is usually a safe operation in
the sense that even with a very large dataset, running str() shouldn’t take too long.

head() tail() function in R


Graph

1. Show comparisons
2. Show causality, mechanism, explanation, systematic structure
3. Show multivariate data
4. Integrate evidence
5. Describe and document the evidence
   1. (Labelling & Annotating)
6. Content, Content, Content
   1. Analytical presentations ultimately stand or fall depending on the quality, relevance, and integrity of their content


Exploratory graphs are usually made very quickly and a lot of them are made in the process of checking out the data.

- Five-number summary: This gives the minimum, 25th percentile, median, 75th percentile, maximum of the data and is quick check on the distribution of the data (see the fivenum())
- Boxplots: Boxplots are a visual representation of the five-number summary plus a bit more information. In particular, boxplots commonly plot outliers that go beyond the bulk of the data. This is implemented via the boxplot() function
- Barplot: Barplots are useful for visualizing categorical data, with the number of entries for each category being proportional to the height of the bar. Think “pie chart” but actually useful. The barplot can be made with the barplot() function.
- Histograms: Histograms show the complete empirical distribution of the data, beyond the five data points shown by the boxplots. Here, you can easily check skewwness of the data, symmetry, multi-modality, and other features. The hist() function makes a histogram, and a handy function to go with it sometimes is the rug() function.
- Density plot: The density() function computes a non-parametric estimate of the distribution of a variables