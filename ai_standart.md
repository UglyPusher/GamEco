# 🤖 AI Semantic Commenting Standard for Core Components

This document defines a consistent system for **semantic comments** used in core C++ code to help AI (and developers) understand and maintain project logic, architecture, and intent.

These comments follow the `[AI: TAG]` format and should be placed near class definitions, methods, or critical logic blocks.

---

## 🔹 Tag List

| Tag           | Description                                                                 |
|---------------|-----------------------------------------------------------------------------|
| `PURPOSE`     | Describes **what** the class/function/block is for                          |
| `DESIGN`      | Explains **why** a design decision was made                                 |
| `USAGE`       | Describes **how** the element is used and any call restrictions             |
| `NOTE`        | Adds important clarification or reminder that is not strictly functional     |
| `WARNING`     | Marks potential misuse, performance issue, or risky edge case                |
| `FUTURE`      | Suggestions or reminders for future extension or improvement                 |

---

## 📌 Examples

### Interface Example: `IStepable.h`
```cpp
// [AI: PURPOSE] Interface for tickable simulation entities.
// [AI: USAGE] Called once per simulation tick by global economy manager.

class IStepable {
public:
    virtual ~IStepable() = default;

    // [AI: PURPOSE] Perform simulation logic at a specific tick.
    // [AI: USAGE] Must not be called manually. Duplicate calls with same tick are ignored.
    virtual void step(uint64_t currentStep) = 0;
};


---

## ✅ Usage Guidelines

* Add `[AI: PURPOSE]` to every class and public method.
* Use `[AI: DESIGN]` on architectural or stateful elements.
* Use `[AI: WARNING]` on potentially unsafe logic.
* Prefer short, declarative comments (1–2 lines).
* Use markdown files (like this one) to describe tagging conventions and document architectural intent.

---

## 🧠 Why This Matters

* Helps AI systems return more relevant, context-aware answers when asked about project structure or design.
* Improves code maintainability and onboarding for developers.
* Enables future automation and smart refactoring.

---

## ✍️ Contributing

All contributors should:

* Follow this tagging style in new files/classes.
* Gradually enrich older code with semantic tags during refactoring.

---
