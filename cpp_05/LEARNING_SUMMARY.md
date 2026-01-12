# CPP Module 05 - Exceptions

## 📚 Vue d'ensemble
Ce module introduit la **gestion des exceptions** en C++, permettant de gérer les erreurs de manière élégante et structurée. Focus sur `try`/`catch`/`throw` et les exceptions personnalisées.

---

## 📋 Exercice 00 : Mommy, when I grow up, I want to be a bureaucrat!

### Concepts clés à maîtriser :

#### 1. **Les exceptions en C++**

**Sans exceptions** (style C) :
```cpp
int divide(int a, int b) {
    if (b == 0)
        return -1;  // Code d'erreur
    return a / b;
}

int result = divide(10, 0);
if (result == -1) {
    // Gérer l'erreur
}
```

**Avec exceptions** (style C++) :
```cpp
int divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division by zero");
    return a / b;
}

try {
    int result = divide(10, 0);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

#### 2. **Syntaxe try/catch/throw**

```cpp
try {
    // Code qui peut lever une exception
    throw std::runtime_error("Something went wrong");
} catch (const std::exception& e) {
    // Gérer l'exception
    std::cerr << e.what() << std::endl;
}
```

#### 3. **Exceptions personnalisées (nested classes)**

```cpp
class Bureaucrat {
    private:
        std::string const _name;
        int _grade;  // 1 (highest) to 150 (lowest)
        
    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high!";
                }
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low!";
                }
        };
};
```

#### 4. **Lancer des exceptions**

```cpp
Bureaucrat::Bureaucrat(std::string name, int grade) 
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;  // Note : décrémente car 1 est le plus haut
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}
```

#### 5. **Attraper des exceptions**

```cpp
try {
    Bureaucrat bob("Bob", 0);  // Trop haut
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << e.what() << std::endl;
} catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << e.what() << std::endl;
}

// Ou attraper toutes les std::exception :
try {
    Bureaucrat bob("Bob", 0);
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

#### 6. **Surcharge de l'opérateur `<<` avec exceptions**

```cpp
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

// Usage :
try {
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

#### 7. **Ce que vous apprenez**
- ✅ Syntaxe `try`/`catch`/`throw`
- ✅ `std::exception` et hiérarchie
- ✅ Créer des exceptions personnalisées
- ✅ Classes imbriquées (nested classes)
- ✅ Méthode `what()` const throw()
- ✅ Gestion d'erreurs élégante

---

## 📝 Exercice 01 : Form up, maggots! (Classes interdépendantes)

### Concepts clés à maîtriser :

#### 1. **Forward declaration**

```cpp
// Form.hpp
class Bureaucrat;  // Forward declaration

class Form {
    public:
        void beSigned(const Bureaucrat& bureaucrat);
};
```

**Pourquoi ?** Éviter les dépendances circulaires :
- `Form.hpp` a besoin de `Bureaucrat`
- `Bureaucrat.hpp` a besoin de `Form`
- Solution : Forward declaration + include dans le `.cpp`

#### 2. **Attributs const**

```cpp
class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
        
    public:
        Form(std::string name, int gradeToSign, int gradeToExec);
};
```

**Initialisation obligatoire** dans la liste d'initialisation :
```cpp
Form::Form(std::string name, int gradeToSign, int gradeToExec)
    : _name(name), _signed(false), 
      _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}
```

#### 3. **Méthodes interdépendantes**

**Dans Bureaucrat** :
```cpp
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

**Dans Form** :
```cpp
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}
```

#### 4. **Exceptions spécifiques au contexte**

```cpp
class Form {
    public:
        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw() {
                return "Form: Grade is too high!";
            }
        };
        
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw() {
                return "Form: Grade is too low!";
            }
        };
};
```

#### 5. **Ce que vous apprenez**
- ✅ Forward declaration
- ✅ Dépendances circulaires
- ✅ Attributs const
- ✅ Méthodes qui lancent des exceptions
- ✅ Communication entre classes
- ✅ try/catch dans les méthodes

---

## 🤖 Exercice 02 : No, you need form 28B, not 28C... (Classes abstraites)

### Concepts clés à maîtriser :

#### 1. **Classe abstraite AForm**

```cpp
class AForm {  // 'A' pour Abstract
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
        
    public:
        virtual ~AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        
        virtual void execute(const Bureaucrat& executor) const = 0;
        //                                                      ^^^^
        //                                                      Méthode pure
        
        void beSigned(const Bureaucrat& bureaucrat);
};
```

#### 2. **Classes dérivées concrètes**

**ShrubberyCreationForm** :
```cpp
class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm(std::string target);
        void execute(const Bureaucrat& executor) const;
};

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
        
    // Créer un fichier avec des arbres ASCII
    std::ofstream file(_target + "_shrubbery");
    file << "      /\\      " << std::endl;
    file << "     /  \\     " << std::endl;
    file << "    /    \\    " << std::endl;
    file << "   /______\\   " << std::endl;
    file << "      ||      " << std::endl;
    file.close();
}
```

**RobotomyRequestForm** :
```cpp
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
        
    std::cout << "* drilling noises *" << std::endl;
    
    srand(time(NULL));
    if (rand() % 2)
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed!" << std::endl;
}
```

**PresidentialPardonForm** :
```cpp
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
        
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" 
              << std::endl;
}
```

#### 3. **Vérifications dans execute()**

**Toujours vérifier** :
1. Le formulaire est signé
2. Le bureaucrate a le grade nécessaire

```cpp
void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExec)
        throw GradeTooLowException();
}
```

#### 4. **Nouvelle exception**

```cpp
class AForm {
    public:
        class FormNotSignedException : public std::exception {
            virtual const char* what() const throw() {
                return "Form is not signed!";
            }
        };
};
```

#### 5. **Méthode executeForm() dans Bureaucrat**

```cpp
void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

#### 6. **Ce que vous apprenez**
- ✅ Classes abstraites avec méthodes pures
- ✅ Implémentation spécifique dans dérivées
- ✅ Vérifications multiples (signed + grade)
- ✅ Manipulation de fichiers (ofstream)
- ✅ Génération aléatoire (rand)
- ✅ Design pattern Template Method

---

## 🏭 Exercice 03 : At least this beats coffee-making (Factory pattern)

### Concepts clés à maîtriser :

#### 1. **Pattern Factory**

```cpp
class Intern {
    public:
        Intern();
        ~Intern();
        
        AForm* makeForm(std::string formName, std::string target);
};
```

#### 2. **Tableau de pointeurs sur fonctions**

```cpp
AForm* Intern::makeForm(std::string formName, std::string target) {
    // Tableau de noms de formulaires
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Tableau de pointeurs sur fonctions de création
    AForm* (Intern::*creators[])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
    
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    
    std::cout << "Form type unknown" << std::endl;
    return NULL;
}
```

#### 3. **Fonctions de création privées**

```cpp
class Intern {
    private:
        AForm* createShrubbery(std::string target);
        AForm* createRobotomy(std::string target);
        AForm* createPresidential(std::string target);
};

AForm* Intern::createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}
```

#### 4. **Usage du Factory**

```cpp
Intern someRandomIntern;
AForm* form;

form = someRandomIntern.makeForm("robotomy request", "Bender");
if (form) {
    // Utiliser le formulaire
    delete form;
}
```

#### 5. **Ce que vous apprenez**
- ✅ Design pattern Factory
- ✅ Tableaux de pointeurs sur fonctions membres
- ✅ Création dynamique d'objets
- ✅ Encapsulation de la logique de création
- ✅ Retour de pointeurs NULL en cas d'erreur

---

## 🎓 Résumé des compétences acquises (Module 05)

### 1. **Gestion des exceptions**
- try/catch/throw
- std::exception
- Exceptions personnalisées
- Méthode what() const throw()

### 2. **Classes interdépendantes**
- Forward declaration
- Attributs const
- Communication entre classes

### 3. **Classes abstraites**
- Méthodes virtuelles pures
- Implémentation dans dérivées
- Template Method pattern

### 4. **Design patterns**
- Factory pattern
- Pointeurs sur fonctions membres
- Encapsulation de création

---

## ⚠️ Pièges courants à éviter

1. **Oublier const throw() dans what()**
```cpp
class MyException : public std::exception {
    public:
        virtual const char* what() const throw() {  // ⚠️ Nécessaire !
            return "Error message";
        }
};
```

2. **Ne pas attraper par référence const**
```cpp
// ❌ Copie l'exception
catch (std::exception e) { }

// ✅ Référence (pas de copie, permet polymorphisme)
catch (const std::exception& e) { }
```

3. **Oublier de vérifier si formulaire signé**
```cpp
void execute(const Bureaucrat& executor) const {
    if (!_signed)  // ⚠️ Toujours vérifier !
        throw FormNotSignedException();
    // ...
}
```

4. **Forward declaration sans include dans .cpp**
```cpp
// Form.hpp
class Bureaucrat;  // Forward declaration

// Form.cpp
#include "Bureaucrat.hpp"  // ⚠️ Include nécessaire ici !
```

5. **Attribut const non initialisé**
```cpp
// ❌ Erreur
Form::Form(std::string name) {
    _name = name;  // _name est const !
}

// ✅ Correct
Form::Form(std::string name) : _name(name) {
}
```

---

## 📊 Hiérarchie std::exception

```
std::exception
    ├── std::bad_alloc
    ├── std::bad_cast
    ├── std::runtime_error
    │   ├── std::overflow_error
    │   └── std::underflow_error
    ├── std::logic_error
    │   ├── std::invalid_argument
    │   └── std::out_of_range
    └── Vos exceptions personnalisées
```

---

## 🔄 Workflow typique avec exceptions

```cpp
// 1. Créer un bureaucrate
try {
    Bureaucrat bob("Bob", 50);
    
    // 2. Créer un formulaire
    ShrubberyCreationForm form("home");
    
    // 3. Signer le formulaire
    bob.signForm(form);
    
    // 4. Exécuter le formulaire
    bob.executeForm(form);
    
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

---

## 💡 Concepts pour le module suivant

Ce module prépare pour :
- **Module 06** : Casts (conversions de types)
- **Module 07** : Templates
- **Module 08-09** : STL et algorithmes

---

## 📖 Pour aller plus loin

- **RAII** : Utiliser les destructeurs pour nettoyer automatiquement
- **Exception safety** : Basic, Strong, No-throw guarantees
- **noexcept** (C++11) : Spécifier qu'une fonction ne lance pas
- **Custom exception avec données** : Stocker des infos dans l'exception
- **Stack unwinding** : Comprendre le déroulement de la pile

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_05 - Gestion des exceptions
