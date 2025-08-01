# [ChatGPT Prompt Engineering for Developers](https://learn.deeplearning.ai/chatgpt-prompt-eng/lesson/1/introduction)

- [ChatGPT Prompt Engineering for Developers](#chatgpt-prompt-engineering-for-developers)
  - [Open AI Enviroment Set-up](#open-ai-enviroment-set-up)
  - [Prompt Engineering Principles](#prompt-engineering-principles)
    - [Principle 1: Write clear and specific instructions](#principle-1-write-clear-and-specific-instructions)
      - [Tactic 1: Use delimiters to clearly indicate distinct parts of the input](#tactic-1-use-delimiters-to-clearly-indicate-distinct-parts-of-the-input)
      - [Tactic 2: Ask for a structured output: JSON, HTML, etc](#tactic-2-ask-for-a-structured-output-json-html-etc)
      - [Tactic 3: Ask the model to check whether conditions are satisfied](#tactic-3-ask-the-model-to-check-whether-conditions-are-satisfied)
      - [Tactic 4: "Few-shot" prompting](#tactic-4-few-shot-prompting)
    - [Principle 2: Give the model time to “think”](#principle-2-give-the-model-time-to-think)
      - [Tactic 1: Specify the steps required to complete a task](#tactic-1-specify-the-steps-required-to-complete-a-task)
      - [Tactic 2: Instruct the model to work out its own solution before rushing to a conclusion](#tactic-2-instruct-the-model-to-work-out-its-own-solution-before-rushing-to-a-conclusion)
  - [Iterative Prompt Development](#iterative-prompt-development)
  - [Tasks Example](#tasks-example)
    - [Text Summarize](#text-summarize)
    - [Infering](#infering)
      - [Sentiment Analysis](#sentiment-analysis)
      - [Infeering Topics](#infeering-topics)
      - [Transform (Text \& Data, include translation, grammar check, correction, etc)](#transform-text--data-include-translation-grammar-check-correction-etc)
      - [Expand](#expand)
    - [Example: Chatbot](#example-chatbot)
      - [the "roles" in Open AI API](#the-roles-in-open-ai-api)
      - [the orderBot Example](#the-orderbot-example)

## Open AI Enviroment Set-up

You need an OpenAI API key stored in a .env file. The setup includes:

**Environment Setup:**

- Import necessary libraries (openai, os, dotenv)
- Load environment variables from .env file
- Set OpenAI API key from environment variable
- Create helper functions for API calls:
  - `get_completion()`: Single prompt completion with temperature=0
  - `get_completion_from_messages()`: Multi-message conversation completion

## Prompt Engineering Principles

### Principle 1: Write clear and specific instructions

#### Tactic 1: Use delimiters to clearly indicate distinct parts of the input

Delimiters can be anything like: ```, """, < >, `<tag> </tag>`, :

**Example:** Uses triple backticks to clearly separate the text to be summarized from the instruction, preventing prompt injection and ensuring the model knows exactly which part to process. Includes both English and Chinese versions of the same prompt pattern.

#### Tactic 2: Ask for a structured output: JSON, HTML, etc

You can limit the output length and specify exact formatting requirements.

**Example:** Requests three fictional books in JSON format with specific keys (book_id, title, author, genre). This demonstrates how to get structured, parseable output instead of free-form text. Includes both English and Chinese versions.

#### Tactic 3: Ask the model to check whether conditions are satisfied

**Example:** Asks the model to check if text contains instructions and reformat them as numbered steps. If no instructions are found, it should return "No steps provided." This demonstrates conditional logic and validation within prompts.

#### Tactic 4: "Few-shot" prompting

**Example:** Shows the model an example conversation between a child and grandparent, where the grandparent responds with philosophical metaphors. The model learns to continue in the same poetic, metaphorical style when the child asks about "resilience."

### Principle 2: Give the model time to “think”

#### Tactic 1: Specify the steps required to complete a task

**Example 1:** Basic step-by-step instructions with line break separators:

1. Summarize text in one sentence
2. Translate to French
3. List names from French summary
4. Output JSON with french_summary and num_names

**Example 2:** Same task but with specific output formatting template that clearly labels each section (Text, Summary, Translation, Names, Output JSON). This version produces more structured, predictable results.

#### Tactic 2: Instruct the model to work out its own solution before rushing to a conclusion

**Example:** Demonstrates forcing the model to work through a problem independently before evaluating a student's answer. The prompt includes:

- A solar panel cost calculation problem
- Student's solution (which contains an error: maintenance is $10/sq ft, not $100/sq ft)
- Structured format requiring the model to:
  1. Solve the problem itself
  2. Compare solutions
  3. Grade the student's work

This prevents the model from being biased by the student's answer and catches calculation errors.

## Iterative Prompt Development

- Iterative refinement of prompts is crucial in developing large language models applications.
- Initial prompt development involves drafting a basic version and gradually improving it through iterative adjustments. eg.
  - tune output limit,
  - specify output format, length, other requirements
- More complex applications benefit from iterative training across multiple samples to evaluate prompt performance averages.
- Detailed optimization across multiple datasets requires significant computational resources.
- Mastery of iterative prompt development and optimization techniques is essential for prompt engineers.
- Practical exercises in Jupyter Notebook enhance understanding of prompt iteration and optimization processes.

![Iterative Prompt Development](Iterative-Prompt-Development.png)

## Tasks Example

### Text Summarize

**Example:** Targeted summarization for specific departments. Creates a 30-word summary of a product review focusing specifically on pricing and perceived value information relevant to the pricing department.

**Example:** Information extraction (vs summarization) for multiple reviews. Loops through 4 reviews and extracts only shipping/delivery-related information in 30 words or less, specifically for the shipping department's use.

### Infering

#### Sentiment Analysis

**Examples of sentiment analysis approaches:**

1. **Basic sentiment:** Single word response ("positive" or "negative")
2. **Emotion detection:** List up to 5 emotions expressed (comma-separated, lowercase)
3. **Specific emotion check:** Yes/no answer for anger detection
4. **Comprehensive analysis:** JSON format extracting sentiment, anger (boolean), item purchased, and brand. Uses "unknown" for missing information.

#### Infeering Topics

**Topic inference examples:**

1. **Open-ended topic extraction:** Identifies 5 topics from text, formatted as 1-2 word phrases in a comma-separated list
2. **Topic validation:** Given a predefined list of topics, returns binary (0/1) indicators showing which topics are present in the text

#### Transform (Text & Data, include translation, grammar check, correction, etc)



**Text transformation examples:**

1. **Multi-language translation:** Translates to French, Spanish, and "English pirate" style
2. **Style transformation:** Converts casual slang to formal business communication
3. **Format conversion:** Transforms JSON data into HTML table with headers
4. **Grammar checking:** Proofreads and corrects text, returns "No errors found" if clean
5. **Enhanced correction:** Proofreads, makes content more compelling, applies APA style, targets advanced readers, outputs in markdown format

#### Expand

**Example:** Automated customer service email generation that:

- Takes a customer review and sentiment analysis as input
- Responds appropriately based on sentiment (positive/neutral = thanks, negative = apology + service referral)
- Uses specific details from the original review
- Maintains professional tone
- Signs as "AI customer agent"

### Example: Chatbot

#### the "roles" in Open AI API

- System Role
  - What it does: Provides setup information or context, including instructions or guidelines.
  - When to use it: Sets the stage for the interaction, specifying rules or tone.
  - Example:
    - "The assistant should maintain a professional tone and avoid discussing politics."
- Assistant Role
  - What it does: Represents the model, responding to user inputs based on the system's context.
  - When to use it: Automatically assumed by the model when replying to user queries.
  - Example:
    - "To integrate OpenAI’s API with your Python application, start by installing the OpenAI Python package using pip..."
- User Role
  - What it does: Represents the human user, guiding the conversation and prompting responses.
  - When to use it: Used whenever the human user makes a statement or asks a question.
  - Example:
    - "Can you explain how to integrate OpenAI’s API with my Python application?"
- Why not just type everything in one big prompt?
  - Clarity and Structure: Keeps the conversation clear and structured.
  - Context Management: Separates different types of context (instructions vs. queries).
  - Control and Flexibility: Provides better control over the conversation's evolution.
  - Note: You’re guiding the model to respond appropriately, not training it directly.

**Example:** Demonstrates the three roles in a conversation:
- **System:** Sets up Shakespearean speaking style
- **User:** Asks for a joke
- **Assistant:** Starts a classic joke setup
- **User:** Responds with "I don't know"

The model continues the conversation in Shakespeare's style with temperature=1 for creativity.

#### the orderBot Example

**OrderBot Implementation:** Complete pizza ordering chatbot with:

**Core Functions:**
- `get_completion()` and `get_completion_from_messages()`: API wrapper functions
- `collect_messages()`: Handles user input, maintains conversation context, updates GUI

**System Setup:**
- Panel GUI with text input and chat button
- Conversation context accumulation
- Styled message display (user vs assistant)

**OrderBot Personality & Process:**
- Automated pizza restaurant service
- Conversational, friendly tone
- Structured ordering flow: greet → collect order → pickup/delivery → summarize → address (if delivery) → payment
- Complete menu with pizzas, toppings, sides, and drinks with pricing
- Clarifies all options and sizes for accurate orders

**Order Summary Generation:** Takes the complete conversation context and generates a structured JSON summary with:
1. Pizza details (including size)
2. List of toppings
3. List of drinks (with sizes)
4. List of sides (with sizes)
5. Total price calculation

This demonstrates how to extract structured data from conversational interactions.