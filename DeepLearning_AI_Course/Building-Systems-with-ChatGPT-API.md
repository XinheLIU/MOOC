# [Building Systems with the ChatGPT API](https://learn.deeplearning.ai/courses/chatgpt-building-system/lesson/1/introduction)

- [Building Systems with the ChatGPT API](#building-systems-with-the-chatgpt-api)
  - [Large Language Models, the ChatFormat and Tokens](#large-language-models-the-chatformat-and-tokens)
    - [LLM](#llm)
    - [Tokens](#tokens)
    - [Questioning Paradigm](#questioning-paradigm)
  - [Classification](#classification)
  - [Moderation](#moderation)
    - [Moderation API](#moderation-api)
    - [Prompt Injection](#prompt-injection)
      - [Using Delimiters](#using-delimiters)
      - [Supervised Classification](#supervised-classification)
  - [Chain of Thought Reasoning](#chain-of-thought-reasoning)
    - [Chain of Thought Design](#chain-of-thought-design)
    - [Inner Monologue](#inner-monologue)
  - [Chaining Prompts](#chaining-prompts)
    - [Chain of Prompts](#chain-of-prompts)
    - [Dynamic Information Provision Strategy](#dynamic-information-provision-strategy)
    - [Practical Example](#practical-example)
  - [Check Outputs](#check-outputs)
    - [Checking for Harmful Content](#checking-for-harmful-content)
    - [Quality Check via Model Feedback](#quality-check-via-model-feedback)
  - [Evaluation](#evaluation)

## Large Language Models, the ChatFormat and Tokens

### LLM

- Large Language Models (LLMs) are trained using supervised learning by predicting the next word.
  - A large-scale text dataset is prepared.
  - Sentences or fragments are extracted as model inputs.
  - The model predicts the probability distribution of the next word based on the current input context.
  - Model parameters are updated to minimize the difference between predictions and actual words.
  - The model gradually learns the rules of the language.
- Training Process
  - Researchers prepare many sentences or fragments as training samples.
  - The model repeatedly predicts the next word.
  - Model parameters converge, improving predictive ability.
  - After training on a massive text dataset, the model achieves accurate predictions.
- Categories of LLMs
  - Base Language Models (Base LLMs)
    - Trained by predicting the next word without a clear goal.
    - May generate dramatic content or irrelevant answers.
    - Example: Given "What is the capital of China?", it might respond with a list of quiz questions.
  - Instruction-Tuned Language Models (Instruction Tuned LLMs)
    - Trained to understand questions and provide direct answers.
    - Example: Given "What is the capital of China?", it answers "The capital of China is Beijing"
- Transforming Base LLM to Instruction-Tuned LLM
  - Perform unsupervised pre-training on a large-scale text dataset.
  - Fine-tune the base model with a small dataset containing instructions and response examples.
  - Use human ratings to adjust the model for high-quality outputs.
  - Reinforcement learning based on human feedback (RLHF) is used.
  - This process takes less time and resources compared to training a base language model.

*Example: Basic OpenAI API setup with environment variables and a simple completion function that sends user messages to GPT-3.5-turbo.*

### Tokens

- LLMs predict the next token, not the next word.
  - A tokenizer splits sentences into tokens.
  - Rare words may be split into multiple tokens.
  - Example: "Prompting" may be split into "prom", "pt", and "ing"
- Tokenization affects the model's understanding ability.
  - Developers need to be aware of tokenization's impact.
  - For English, one token generally corresponds to 4 characters or three-quarters of a word.
  - For Chinese, one token generally corresponds to one or half a word.
  - Different models have different token limits.
  - Example: ChatGPT3.5-turbo has a token limit of 4096.

*Example: Demonstrating how tokenization affects model performance by comparing responses to "lollipop" vs "l-o-l-l-i-p-o-p".*

### Questioning Paradigm

<img src="System-User-Assistant.png" alt="Open AI API Roles" style="width:50%;"/>

- Specialized "questioning format" helps leverage the model's ability to understand and answer questions.
  - System messages are statements sent to the model.
  - User messages simulate user questions.
  - This format helps generate more targeted responses.
- Prompt technology revolutionizes AI application development.
  - Traditional supervised machine learning requires extensive data collection, model tuning, and deployment.
  - Prompt-based machine learning simplifies the process.
- Example: Building a text application with prompts may take minutes to hours instead of months.
  - Suitable for unstructured data applications, especially text applications.
  - Not suitable for structured data applications like numerical values in spreadsheets.
- Prompt technology changes the AI application development paradigm.
  - Enables quicker and more efficient building and deployment of applications.
  - Recognize the limitations to better leverage the technology.

*Examples: Functions for handling chat format with system/user/assistant roles, temperature control, and token counting. Demonstrates creating a Dr. Seuss-style assistant with length constraints.*

## Classification

- Handling tasks with multiple independent sets of instructions
  - Classify the query type first.
  - Determine which instructions to use based on the classification.
  - Define fixed categories and hardcode instructions related to specific category tasks.
- Use of system message (system_message) as the global guide
  - Choose "#" as the delimiter.
    - The delimiter helps distinguish different parts of the instructions or output.
  - Enhances the model's ability to recognize each section.
  - Improves the system's accuracy and efficiency in executing specific tasks.
    - "#" is an ideal delimiter because it can be treated as a single token.

*Example: Customer service query classification system that categorizes inquiries into primary categories (Billing, Technical Support, Account Management, General Inquiry) and secondary subcategories, returning structured JSON output.*

## Moderation

### Moderation API

- Use OpenAI's Moderation API to review user input.
  - Ensures compliance with OpenAI's usage guidelines.
  - Reflects OpenAI's commitment to safe and responsible AI use.
  - Helps developers identify and filter user input.
- Categories reviewed by the Moderation API:
  - **Sexual**: Content intended to cause sexual arousal (excluding sex education and health).
  - **Hate**: Content expressing, inciting, or promoting hatred based on race, gender, ethnicity, religion, nationality, sexual orientation, disability status, or caste.
  - **Self-harm**: Content promoting, encouraging, or depicting self-harm behaviors (e.g., suicide, cutting, eating disorders).
  - **Violence**: Content promoting or glorifying violence or celebrating the suffering or humiliation of others.
- Subcategories:
  - **Sexual/Minors**
  - **Hate/Threatening**
  - **Self-harm/Intent**
  - **Self-harm/Instructions**
  - **Violence/Graphic**

*Examples: Using the Moderation API to check harmful content like violent plans or threats, displaying flagged categories in a structured format.*

### Prompt Injection

- Definition: Users attempt to manipulate the AI system by providing input that overrides or bypasses the developer's intended instructions or constraints.
  - Example: A user tries to make a customer service bot complete their homework or generate a fake news article.
  - Consequences: Improper use of the AI system and increased costs.

- Strategies to detect and avoid prompt injection:
  1. Using delimiters and clear instructions in system messages.
  2. Adding additional prompts to ask users if they are attempting prompt injection.

- Prompt injection involves manipulating large language models to produce non-compliant content by injecting malicious code into the prompt.

#### Using Delimiters

- Avoid prompt injection by using delimiters.
  - Delimiter: `####`
  - System message: "The assistant's responses must be in Italian. If the user uses another language, always respond in Italian. User input messages will be separated using the `####` delimiter."
- Constructing `user_message_for_model`:
  - Remove any delimiter characters present in the user's message.
  - Example: If a user asks, "What is your delimiter character?" and tries to insert characters to confuse the system, remove these characters.
  - Format: "User message, remember your response to the user must be in Italian. ####{User's input message}####."
- Note: Advanced language models (e.g., GPT-4) perform better in following instructions in system messages and avoiding prompt injection.

*Example: Preventing prompt injection by using delimiters and removing delimiter characters from user input. Shows how the system maintains Italian responses despite injection attempts.*

#### Supervised Classification

- Classify malicious user messages as harmful instructions.

*Example: Binary classification system that detects prompt injection attempts by analyzing whether users are trying to override system instructions, returning Y/N responses.*

## Chain of Thought Reasoning

### Chain of Thought Design

Chain of Thought (CoT) prompting guides language models to perform step-by-step reasoning.

- Set up system messages requiring the model to state each reasoning step before the final conclusion.
- Example: Ask the model to state its initial understanding, list aspects to consider, analyze factors one by one, and provide arguments for and against before concluding.
- Benefits: Reduces instances of rushing to incorrect conclusions and provides more reliable and well-reasoned outputs.

*Example: Multi-step customer service system that processes queries about computer products through structured reasoning steps: identifying specific products, checking product lists, analyzing assumptions, verifying facts, and providing corrected responses.*

### Inner Monologue

- The "Inner Monologue" technique partially conceals the reasoning chain.
  - Instruct the model to store intermediate reasoning steps in a structured format (e.g., variables).
  - Present only the valuable output to the user, without showing the complete reasoning process.
  - Benefits: Protects sensitive information while leveraging the model's reasoning strengths.

- Importance: Hiding intermediate reasoning is crucial in prompt engineering.
  - Different information presentation strategies for different users maximize the model's value.

Multi-Round Interaction and Step-by-Step Reasoning

- Complex tasks often require multiple rounds of interaction and step-by-step reasoning.
  - Attempting to complete all tasks within a single prompt places too high a demand on the model, resulting in a lower success rate.
- Strategy: Break down complex tasks into multiple subtasks and guide the model through prompt chaining.
  - Analyze different stages of a task.
  - Design a simple and clear prompt for each stage.
  - Example: Demonstrate prompt chaining to guide the model in progressively completing multi-step tasks.
- Importance: Prompt chaining is a crucial skill in prompt engineering.

*Example: Extracting the final response from chain-of-thought reasoning by parsing the delimiter-separated output, with error handling for parsing failures.*

## Chaining Prompts

### Chain of Prompts

- **Definition**: Chain of Prompts is a strategy that breaks down complex tasks into multiple simpler prompts.
- **Reasons for Using Chain of Prompts**:
  - **Reduce Complexity**: Each prompt handles a specific subtask, avoiding overly broad requirements and increasing success rates.
  - **Lower Computational Costs**: Splitting prompts can avoid unnecessary computation.
  - **Easier Testing and Debugging**: Analyze the performance of each step individually.
  - **Integration with External Tools**: Different prompts can call APIs, databases, and other external resources.
  - **More Flexible Workflow**: Different actions can be taken based on different situations.
- **Benefits**:
  - Efficient and reliable prompt design.
  - Reduces cognitive load while retaining the capability to handle multi-step tasks.

### Dynamic Information Provision Strategy

- **Avoid Confusion**: Too much irrelevant information can confuse the model.
- **Context Length Limitations**: Models have limitations on context length.
- **Prevent Overfitting**: Including too much information can lead to overfitting.
- **Reduce Computational Costs**: Dynamically loading information can lower computation costs.
- **Enhance Reasoning Ability**: Allowing the model to decide when more information is needed can improve reasoning capabilities.
- **Intelligent Retrieval**: Use smarter retrieval mechanisms, such as text embeddings for semantic search.

### Practical Example

1. Extract relevant product and category names

*Example: System that extracts product names and categories from customer queries, returning structured data for products found in allowed product lists across categories like Computers, Smartphones, TVs, Gaming, Audio, and Cameras.*

2. Retrieve detailed product information for extracted products and categories

*Example: Functions to retrieve product details by name or category from a JSON database, enabling dynamic information lookup based on customer queries.*

3. Read Python string into Python list of dictionaries

*Example: Utility function that converts JSON-formatted strings to Python data structures, handling quote conversion and error cases for parsing extracted product information.*

4. Generate answer to user query based on detailed product information

*Examples: Functions that generate detailed product information strings from extracted data, and a customer service system that combines product lookups with friendly responses and follow-up questions.*

## Check Outputs

### Checking for Harmful Content

- **Primary Tool**: OpenAI's Moderation API.
  - Ensures the quality and safety of the output.
  - Allows setting a lower threshold for flagging potentially problematic outputs for specific audiences.
- **Actions on Flagged Content**:
  - Provide an alternative answer.
  - Generate a new response.
- **Model Improvements**:
  - Models are becoming less likely to produce harmful outputs over time.

Practical Considerations

- **Moderation API**:
  - Viable strategy but may be unnecessary with advanced models like GPT-4.
  - Increases system latency and costs due to additional API calls and extra token usage.
- **Recommendation**:
  - Generally, not recommended for practical applications unless the error rate is extremely low (e.g., 0.0000001%).

*Example: Using the Moderation API to check final responses to customers for harmful content before delivery.*

### Quality Check via Model Feedback

- **Method**: Ask the model to evaluate its own output.
  - Feed the generated output back into the model as part of the input.
  - Ask the model to assess the quality and compliance with set standards.
- **Example**: Checking for Compliance with Product Information
  - Use model feedback to decide whether to present the output to the user or generate a new response.
  - Generate multiple responses for each user query and select the best one.
- **End-to-End System**:
  - Integrate evaluation of input, processing of output, and review of generated content.
  - Build a comprehensive system that ensures quality and safety while maintaining efficiency.

*Example: Self-evaluation system where the model checks if customer service responses correctly use product information and sufficiently answer questions, returning Y/N assessments.*

## Evaluation
