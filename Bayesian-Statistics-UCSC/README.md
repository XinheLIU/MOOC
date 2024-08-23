# Bayesian Statistics

- [Bayesian Statistics](#bayesian-statistics)
	- [Module 1](#module-1)
	- [Module 2](#module-2)
		- [Confident Interval](#confident-interval)
	- [Module 3](#module-3)
	- [Important Concepts and Formulas](#important-concepts-and-formulas)
		- [Bayesian Inference](#bayesian-inference)
			- [Effective Sample Size](#effective-sample-size)
			- [Credible Intervals](#credible-intervals)
			- [Bayesian Regression](#bayesian-regression)
	- [Module 4](#module-4)
		- [Choose Priors](#choose-priors)
			- [Conjugate Priors](#conjugate-priors)
			- [Uninformed priors](#uninformed-priors)
			- [Jeffery's Priors](#jefferys-priors)
			- [Other priors](#other-priors)
			- [Empirical Bayesian Analysis](#empirical-bayesian-analysis)

## Module 1

- definitions of probability, conditional probability.
- Bayes’ Theorem.
- probability distributions, probability density functions.

## Module 2

- Likelihood function.
- Frequentist Confidence interval.
- Bernoulli or Binomial outcome. (confidence interval)
- Maximum Likelihood Estimate
- a posterior from a prior and a Bernoulli or binomial likelihood.
- the posterior as a representation of information and uncertainty.
- **Bayesian posterior interval.**

### Confident Interval

> The misintepretation happened most is the "confidence" itself is the probability that p is in the interval

But we can also step back and say what does this interval really mean. What does it mean when I say we're 95% confident?

Under the frequentist paradigm, what this means is we have to think back to our infinite hypothetical sequence of events. So if we were to repeat this trial an infinite number of times, or an arbitrary large number of times.

Each time we create a confidence interval in this way based on the data we observe. Than on average 95% of the intervals we make will contain the true value of p.

This makes senses along where in frequency explanation. On the other hand we might want to know something about this particular interval. Does this interval contain the true p. What's the probability that this interval contains a true p? Well, **we don't know for this particular interval.** But under the frequentist paradigm, we're assuming that there is a fixed right answer for p. Either p is in that interval or it's not in that interval.

So technically, from a frequentist perspective, the probability that p is in this interval is either 0 or 1. This is not a particularly satisfying explanation. In the other hand when we get to the Bayesian approach we will be able to compute an interval and actually say there is probably a p is in this interval is 95% based on a random interpretation of an unknown parameter

## Module 3

- the prior as representing information.
- conjugate priors.
- posterior mean as a **weighted average of the prior mean and the data estimates**, and understand the concept of an effective sample size of a prior.
- posterior probabilities for Bernoulli, binomial, and Poisson likelihoods.

## Important Concepts and Formulas

### [Bayesian Inference](https://en.wikipedia.org/wiki/Bayesian_inference#Formal_description_of_Bayesian_inference)

Generally if one has enough data, the information in the data will overwhelm the invasion of prior. And so it, prior is not particularly important in terms of what you get for the posterior.

#### Effective Sample Size

If we decompose the posterior mean to be the weighted average of prior mean and data mean, the weight of prior multiplied by the weight of data * n is the **effective sample size of prior**

#### Credible Intervals

The "confidence interval" for **parameters** under Bayesian approach.

#### [Bayesian Regression](https://en.wikipedia.org/wiki/Bayesian_linear_regression)

## Module 4

• posterior probabilities for exponential and normal likelihoods.
• Understand non-informative priors. 
• Perform a Bayesian linear regression analysis.

### Choose Priors

A useful concept in terms of choosing priors is that of **calibration.**

Calibration of predictive intervals. If we make an interval where we're saying we predict 95% of new data points will occur in this interval. It would be good if in reality 95% of new data points actually did fall in that interval. How do we calibrate to reality? This is actually more frequent as concept but this is important for practical substicle purposes that are results do reflect reality.

So we can compute a predictive interval, this is **an interval such that 95% of new observations** are expected to fall into it. So it's an interval for the data, for y or x. Rather than an interval for theta, like we've been looking at.

#### [Conjugate Priors](https://en.wikipedia.org/wiki/Conjugate_prior#cite_note-postpred-4)

A family of distributions is referred to as conjugate if when you use a member of that family as a prior, you get another member of that family as your posterior.

#### [Uninformed priors](https://en.wikipedia.org/wiki/Prior_probability#Uninformative_priors)

For many problems there does exist a prior, typically an improper prior which will lead you to get the same point estimates as under frequentists. Improper priors are okay as long as the posterior itself is proper.

vague prior for normal prior of normal data is to set variance to be infinite, this will just lead the point estimate to be same as MLE.

#### [Jeffery's Priors](https://en.wikipedia.org/wiki/Jeffreys_prior)

Jeffreys prior is to find this prior proportional to the square root of the Fisher Information. In most cases, this will be an **improper prior**. For the example of normal data.This prior will then be invariant transformation will be putting the same information into the prior. Even if we use a different parameterization for the normal.

In the example of Bernoulli or binomial, the Jeffreys prior turns out to be theta to the minus one-half, one minus theta, to the minus one-half, which is a beta distribution with parameters one-half and one-half. This is a rare example where the Jeffreys prior turns out to be a proper prior.You'll note that this prior actually does have some information in it. It's equivalent to an effective sample size of one data point. However this information will then be the same, not depending on the prioritization we use. This case we have theta as a probability. But another alternative, used in probabilities calculations, sometimes we model things on a logistics scale. And in that case, we can transfer everything and using the Jeffreys prior, we'll maintain the exact same information.

#### Other priors

Other possible approaches to objective basing inference include priors such as **reference priors** and **maximum entropy priors**

#### Empirical Bayesian Analysis

 The idea in empirical base is that you use the data to help inform your prior, such as using the mean of the data to set the mean of the prior distribution. This approach often leads to reasonable point estimates in your posterior. However, **it's sort of cheating, because you're using the data twice**. And as a result, it may lead to improper uncertainty estimates.