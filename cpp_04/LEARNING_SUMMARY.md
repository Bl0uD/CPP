# CPP Module 04 - Polymorphisme et Classes abstraites

## 📚 Vue d'ensemble
Ce module introduit le **polymorphisme**, les **méthodes virtuelles** et les **classes abstraites**. Focus sur la liaison dynamique et les interfaces en C++.

---

## 🐾 Exercice 00 : Polymorphisme (Classes virtuelles)

### Concepts clés à maîtriser :

#### 1. **Le problème sans `virtual`**
```cpp
class Animal {
    public:
        void makeSound() const {
            std::cout << "Animal sound" << std::endl;
        }
};

class Dog : public Animal {
    public:
        void makeSound() const {
            std::cout << "Woof!" << std::endl;
        }
};

Animal* animal = new Dog();
animal->makeSound();  // Affiche "Animal sound" ❌
```

#### 2. **Solution : mot-clé `virtual`**
```cpp
class Animal {
    public:
        virtual void makeSound() const {
            std::cout << "Animal sound" << std::endl;
        }
        virtual ~Animal() {}  // Destructeur virtuel OBLIGATOIRE
};

class Dog : public Animal {
    public:
        void makeSound() const {
            std::cout << "Woof!" << std::endl;
        }
};

Animal* animal = new Dog();
animal->makeSound();  // Affiche "Woof!" ✅
```

#### 3. **Destructeur virtuel (CRUCIAL)**
```cpp
class Animal {
    public:
        virtual ~Animal() {
            std::cout << "Animal destructor" << std::endl;
        }
};

class Dog : public Animal {
    public:
        ~Dog() {
            std::cout << "Dog destructor" << std::endl;
        }
};

Animal* animal = new Dog();
delete animal;
// Avec virtual :
//   1. Dog destructor
//   2. Animal destructor  ✅

// Sans virtual :
//   1. Animal destructor seulement  ❌ (fuite mémoire!)
```

#### 4. **Classe WrongAnimal (contre-exemple)**
```cpp
class WrongAnimal {
    public:
        void makeSound() const {  // PAS virtual
            std::cout << "Wrong sound" << std::endl;
        }
};

class WrongCat : public WrongAnimal {
    public:
        void makeSound() const {
            std::cout << "Wrong meow" << std::endl;
        }
};

WrongAnimal* animal = new WrongCat();
animal->makeSound();  // "Wrong sound" (pas "Wrong meow")
```

#### 5. **Liaison statique vs dynamique**

**Liaison statique** (sans `virtual`) :
- Décidé à la **compilation**
- Basé sur le **type du pointeur**
- Plus rapide mais moins flexible

**Liaison dynamique** (avec `virtual`) :
- Décidé à l'**exécution**
- Basé sur le **type réel de l'objet**
- Un peu plus lent mais flexible

#### 6. **Ce que vous apprenez**
- ✅ Mot-clé `virtual`
- ✅ Polymorphisme
- ✅ Destructeur virtuel (obligatoire!)
- ✅ Liaison dynamique
- ✅ V-table (table virtuelle)

---

## 🧠 Exercice 01 : I don't want to set the world on fire (Deep copy)

### Concepts clés à maîtriser :

#### 1. **Ajout d'un attribut complexe**
```cpp
class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
};

class Dog : public Animal {
    private:
        Brain* _brain;  // Pointeur vers Brain
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
};
```

#### 2. **Constructeur avec allocation**
```cpp
Dog::Dog() : Animal("Dog") {
    _brain = new Brain();  // Allocation dynamique
    std::cout << "Dog constructor" << std::endl;
}
```

#### 3. **Destructeur avec libération**
```cpp
Dog::~Dog() {
    delete _brain;  // Libération obligatoire
    std::cout << "Dog destructor" << std::endl;
}
```

#### 4. **Deep copy dans le constructeur de copie**
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);  // Nouvelle allocation + copie
    std::cout << "Dog copy constructor" << std::endl;
}
```

**Pourquoi deep copy ?**
```cpp
// Shallow copy (❌ MAUVAIS)
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = other._brain;  // Les deux pointent vers le même Brain!
}

// Problème :
Dog dog1;
Dog dog2(dog1);  // dog1._brain == dog2._brain
// Quand dog1 est détruit, dog2._brain devient invalide!
```

#### 5. **Deep copy dans l'opérateur d'assignation**
```cpp
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;              // 1. Libérer l'ancien
        _brain = new Brain(*other._brain);  // 2. Copier le nouveau
    }
    return *this;
}
```

#### 6. **Test de fuite mémoire**
```cpp
void test() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;  // Doit appeler ~Dog() puis ~Animal()
    delete i;  // Doit appeler ~Cat() puis ~Animal()
}
// Sans virtual ~Animal(), Brain* fuite !
```

#### 7. **Ce que vous apprenez**
- ✅ Deep copy vs shallow copy
- ✅ Gestion mémoire avec héritage
- ✅ Allocation/libération dans classes dérivées
- ✅ Importance du destructeur virtuel
- ✅ Rule of Three avec pointeurs

---

## 🚫 Exercice 02 : Abstract class (Classes abstraites)

### Concepts clés à maîtriser :

#### 1. **Méthode virtuelle pure**
```cpp
class AAnimal {  // 'A' pour Abstract
    public:
        virtual void makeSound() const = 0;  // = 0 rend la méthode pure
        //                             ^^^^
        virtual ~AAnimal() {}
};
```

#### 2. **Classe abstraite (interface)**
Une classe avec **au moins une** méthode virtuelle pure :
- ❌ **Ne peut pas être instanciée**
- ✅ **Peut être utilisée comme pointeur/référence**
- ✅ **Force les classes dérivées à implémenter les méthodes**

```cpp
// ❌ Erreur de compilation
AAnimal* animal = new AAnimal();

// ✅ Correct
AAnimal* animal = new Dog();
```

#### 3. **Implémentation obligatoire dans les dérivées**
```cpp
class Dog : public AAnimal {
    public:
        void makeSound() const {  // DOIT être implémentée
            std::cout << "Woof!" << std::endl;
        }
};

class BadDog : public AAnimal {
    // ❌ makeSound() non implémentée
    // → BadDog est aussi abstraite !
};
```

#### 4. **Utilisation comme interface**
```cpp
void animalSound(const AAnimal& animal) {
    animal.makeSound();  // Polymorphisme
}

Dog dog;
Cat cat;
animalSound(dog);  // "Woof!"
animalSound(cat);  // "Meow!"
```

#### 5. **Classe abstraite pure (interface pure)**
```cpp
class IAnimal {
    public:
        virtual ~IAnimal() {}
        virtual void makeSound() const = 0;
        virtual void move() const = 0;
        virtual void eat() const = 0;
};
// Toutes les méthodes sont pures → Interface pure
```

#### 6. **Ce que vous apprenez**
- ✅ Méthodes virtuelles pures (`= 0`)
- ✅ Classes abstraites
- ✅ Interfaces en C++
- ✅ Contrats d'implémentation
- ✅ Design par interface

---

## 🎓 Résumé des compétences acquises (Module 04)

### 1. **Polymorphisme**
- Méthodes virtuelles
- Liaison dynamique
- V-table
- Destructeur virtuel obligatoire

### 2. **Gestion mémoire avancée**
- Deep copy avec pointeurs
- Allocation/libération avec héritage
- Éviter les fuites mémoire
- Rule of Three avec ressources

### 3. **Classes abstraites**
- Méthodes virtuelles pures
- Interfaces
- Classes non instanciables
- Contrats d'implémentation

### 4. **Design patterns**
- Polymorphisme
- Interface Segregation
- Dependency Inversion

---

## ⚠️ Pièges courants à éviter

1. **Oublier le destructeur virtuel**
```cpp
class Animal {
    public:
        virtual ~Animal() {}  // ⚠️ OBLIGATOIRE avec virtual
};
```

2. **Shallow copy avec pointeurs**
```cpp
// ❌ Erreur
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = other._brain;  // Shallow copy !
}

// ✅ Correct
Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);  // Deep copy
}
```

3. **Oublier de libérer dans le destructeur**
```cpp
Dog::~Dog() {
    delete _brain;  // ⚠️ Ne pas oublier !
}
```

4. **Oublier de delete l'ancien dans operator=**
```cpp
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;  // ⚠️ Libérer l'ancien avant !
        _brain = new Brain(*other._brain);
    }
    return *this;
}
```

5. **Méthode virtuelle non const**
```cpp
// Si makeSound() est const dans la base :
class Animal {
    public:
        virtual void makeSound() const = 0;
};

class Dog : public Animal {
    public:
        void makeSound() const {  // ⚠️ const obligatoire !
            // ...
        }
};
```

---

## 📊 Comparaison des types de méthodes

| Type | Syntaxe | Implémentation | Surcharge |
|------|---------|----------------|-----------|
| **Normale** | `void func()` | Obligatoire | Facultative |
| **Virtuelle** | `virtual void func()` | Obligatoire | Facultative |
| **Virtuelle pure** | `virtual void func() = 0` | ❌ Interdit | Obligatoire |

---

## 🔍 V-table (Table virtuelle)

**Avec méthodes virtuelles**, le compilateur crée une **V-table** :

```cpp
class Animal {
    public:
        virtual void makeSound();
        virtual void move();
};

// V-table pour Animal :
// [0] → Animal::makeSound
// [1] → Animal::move

class Dog : public Animal {
    public:
        void makeSound();  // Surcharge
};

// V-table pour Dog :
// [0] → Dog::makeSound      (surchargé)
// [1] → Animal::move        (hérité)
```

**Coût** :
- Mémoire : 1 pointeur par objet (vers sa V-table)
- Performance : 1 indirection supplémentaire

---

## 🏗️ Design avec interfaces

**Mauvais design** :
```cpp
class Dog {
    void bark();
    void run();
    void eat();
};

class Cat {
    void meow();
    void run();
    void eat();
};
// Code dupliqué !
```

**Bon design** :
```cpp
class IAnimal {
    public:
        virtual void makeSound() const = 0;
        virtual void move() const = 0;
        virtual ~IAnimal() {}
};

class Dog : public IAnimal {
    void makeSound() const { /* Woof */ }
    void move() const { /* Run */ }
};

class Cat : public IAnimal {
    void makeSound() const { /* Meow */ }
    void move() const { /* Walk */ }
};
```

---

## 💡 Concepts pour les modules suivants

Ce module prépare pour :
- **Module 05** : Exceptions
- **Module 06** : Casts (static_cast, dynamic_cast, etc.)
- **Module 08-09** : Conteneurs STL et algorithmes

---

## 📖 Pour aller plus loin

- **override** keyword (C++11) : Sécurité supplémentaire
- **final** keyword (C++11) : Empêcher la surcharge
- **Multiple inheritance** : Héritage de plusieurs classes
- **Virtual inheritance** : Résoudre le problème du diamant
- **SOLID principles** : Open/Closed, Liskov Substitution
- **Design patterns** : Factory, Strategy, Observer

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_04 - Polymorphisme et Classes abstraites
