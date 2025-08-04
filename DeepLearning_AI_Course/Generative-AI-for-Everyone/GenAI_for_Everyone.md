# Generative AI for Everyone

> **Course**: [Generative AI for Everyone](https://www.coursera.org/learn/generative-ai-for-everyone/lecture/YXvSW/trying-generative-ai-code-yourself-optional)  
> **Tags**: [[DeepLearning.AI Courses]]

---

## Table of Contents
- [What is Generative AI?](#what-is-generative-ai)
- [LLM Capabilities and Limitations](#llm-capabilities-and-limitations)
- [Effective Prompting Strategies](#effective-prompting-strategies)
- [GenAI Project Workflow](#genai-project-workflow)
- [Key Technologies](#key-technologies)
- [Model Sizes and Capabilities](#model-sizes-and-capabilities)
- [Closed vs Open Source Models](#closed-vs-open-source-models)
- [AI Applications](#ai-applications)
- [Opportunity Analysis](#opportunity-analysis)
- [Building an AI Team](#building-an-ai-team)

---

## What is Generative AI?

Generative AI (GenAI) is a general-purpose technology with diverse applications across multiple domains:

### Core Capabilities

#### 📖 **Information Retrieval & Processing**
- **Reading & Analysis**
  - Proof-reading and editing
  - Summarization of long documents
  - Content extraction and organization

#### ✍️ **Content Creation**
- **Writing Assistance**
  - Brainstorming (e.g., "Brainstorm five ideas for increasing cookie sales in Q4")
  - Creative writing with specific parameters
  - Translation between languages
  - Content generation with detailed requirements

#### 💬 **Conversational AI**
- **Specialized Chatbots**
  - **Recommended Deployment Strategy**:
    1. Start with internal-facing chatbots
    2. Deploy with human-in-the-loop for error checking
    3. Only allow direct customer communication after safety validation

---

## LLM Capabilities and Limitations

### ✅ **What LLMs Can Do**
- Follow detailed instructions to complete tasks
- Process and generate human-like text
- Perform reasoning and analysis
- Handle creative and analytical tasks

### ❌ **What LLMs Cannot Do**
- **Knowledge Limitations**:
  - No access to real-time internet or external resources
  - Knowledge cutoff date (no current events after training)
  - No company-specific or business-specific training
  - No memory of previous interactions or tasks

- **Technical Constraints**:
  - **Hallucination**: May generate false or misleading information
  - **Input/Output Length**: Limited by token constraints
  - **Structured Data**: Poor performance with numerical data, spreadsheets, databases
  - **Bias and Toxicity**: May reflect training data biases

### 🎯 **Capability Assessment Framework**
Ask yourself: *"Can a fresh college graduate follow the instructions in the prompt to complete the task?"*

---

## Effective Prompting Strategies

### 📝 **Best Practices**

1. **Be Detailed and Specific**
   - Provide sufficient context for the LLM to understand the task
   - Describe the desired outcome in detail
   - Include relevant constraints and requirements

2. **Guide the Model's Thinking Process**
   - Encourage step-by-step reasoning
   - Ask the model to explain its approach
   - Use chain-of-thought prompting for complex tasks

3. **Experiment and Iterate**
   - Test different prompt formulations
   - Refine based on results
   - Use A/B testing for optimal performance

---

## GenAI Project Workflow

### 🔄 **Four-Phase Process**

```
Scope Project → Build/Improve System → Internal Evaluation → Deploy and Monitor
```

1. **Scope Project**: Define objectives, requirements, and success metrics
2. **Build/Improve System**: Develop and refine the AI solution
3. **Internal Evaluation**: Test with internal stakeholders and validate performance
4. **Deploy and Monitor**: Launch and continuously monitor for improvements

---

## Key Technologies

### 🔍 **RAG (Retrieval-Augmented Generation)**

**The Big Idea**: LLMs have extensive general knowledge but lack specific, current, or proprietary information.

**How It Works**:
- Provide relevant context in the prompt
- Ask the LLM to read and process specific information
- Use the model as a reasoning engine rather than an information source

**Benefits**:
- Access to current information
- Company-specific knowledge integration
- Reduced hallucination through grounded responses

### 🎯 **Fine-tuning (1,000-10,000 words)**

**When to Use**:
- Tasks that are difficult to define in prompts
- Domain-specific knowledge acquisition (medical, legal, etc.)
- Smaller model optimization for specific tasks

**Advantages**:
- Lower deployment costs and latency
- Mobile/laptop compatibility (edge devices)
- Specialized performance

### 🏗️ **Pre-training (100B+ words)**

**Use Cases**:
- Highly specialized domains (e.g., Bloomberg GPT)
- Custom language models for specific industries
- Proprietary knowledge integration

---

## Model Sizes and Capabilities

| Model Size | Capabilities | Example Applications |
|------------|--------------|---------------------|
| **1B Parameters** | Pattern matching, basic world knowledge | Restaurant review sentiment analysis |
| **10B Parameters** | Greater world knowledge, basic instruction following | Food order chatbot |
| **100B+ Parameters** | Rich world knowledge, complex reasoning | Brainstorming partner, advanced analysis |

---

## Closed vs Open Source Models

### 🔒 **Closed-Source Models (Cloud APIs)**

**Advantages**:
- ✅ Easy integration into applications
- ✅ Access to large, powerful models
- ✅ Relatively inexpensive
- ✅ Regular updates and improvements

**Disadvantages**:
- ❌ Vendor lock-in risk
- ❌ Limited customization
- ❌ Dependency on external services

### 🔓 **Open-Source Models**

**Advantages**:
- ✅ Full control over the model
- ✅ On-premises deployment (PC, servers, etc.)
- ✅ Complete data privacy and access control
- ✅ No vendor dependencies

**Disadvantages**:
- ❌ Requires technical expertise
- ❌ Higher computational requirements
- ❌ Limited model sizes for local deployment

---

## AI Applications

### 🤝 **Augmentation**
- **Definition**: Help humans with tasks or enable previously impossible capabilities
- **Example**: Recommend responses for customer service agents to edit and approve

### 🤖 **Automation**
- **Definition**: Automatically perform tasks without human intervention
- **Example**: Automatically transcribe and summarize customer call records

---

## Opportunity Analysis

### 🔍 **Identifying AI Opportunities**

1. **Workflow Analysis**
   - Break down jobs into specific workflows
   - Identify repetitive or time-consuming tasks
   - Look for information processing bottlenecks

2. **Replacement Risk Assessment**
   - **Technical Feasibility**: Can AI do it?
     - Apply the "fresh college graduate" test
     - Experiment with LLM prompting
     - Consult AI engineers for RAG/fine-tuning assessment
   
   - **Business Value**: How valuable is AI augmentation/automation?
     - Time savings analysis
     - Cost reduction potential
     - Consistency improvements
     - Quality enhancements

---

## Building an AI Team

### 👥 **Core Team Roles**

#### **Software Engineer**
- **Responsibilities**: Writing software applications
- **Requirements**: LLM/prompting basics knowledge
- **Focus**: System integration and deployment

#### **Machine Learning Engineer**
- **Responsibilities**: Implementing AI systems
- **Requirements**: LLMs, prompting, RAG, fine-tuning expertise
- **Focus**: Model optimization and technical implementation

#### **Product Manager**
- **Responsibilities**: Project identification and scoping
- **Focus**: Business requirements and user needs

### 🔧 **Supporting Roles**

#### **Data Engineer**
- **Responsibilities**: Data organization and quality assurance
- **Focus**: Data pipeline management

#### **Data Scientist**
- **Responsibilities**: Data analysis and business recommendations
- **Focus**: Insights and decision support

#### **Project Manager**
- **Responsibilities**: Project coordination and execution
- **Focus**: Timeline and resource management

#### **Machine Learning Researcher**
- **Responsibilities**: Advanced AI technology development
- **Focus**: Innovation and cutting-edge solutions

### 💡 **Note on Prompt Engineers**
- Usually not hired as a dedicated role
- Skills are often distributed across team members
- Focus on building prompting expertise within existing roles

---

## Reference

*This document summarizes key concepts from the "Generative AI for Everyone" course by DeepLearning.AI*