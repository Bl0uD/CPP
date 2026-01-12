# CPP Module 06 - Casts (Conversions de types)

## 📚 Vue d'ensemble
Ce module explore les différents types de **casts** (conversions de types) en C++. Focus sur les conversions sécurisées et les spécificités du C++ par rapport au C.

---

## 🔄 Exercice 00 : Conversion of scalar types (Détection et conversion)

### Concepts clés à maîtriser :

#### 1. **Types de littéraux en C++**

**char literals** :
```cpp
'c', 'a', '0'
```

**int literals** :
```cpp
0, -42, 42, 2147483647
```

**float literals** :
```cpp
0.0f, -4.2f, 4.2f, nanf, +inff, -inff
```

**double literals** :
```cpp
0.0, -4.2, 4.2, nan, +inf, -inf
```

#### 2. **Classe non instanciable (static utility class)**

```cpp
class ScalarConverter {
    private:
        ScalarConverter();                          // Private
        ScalarConverter(const ScalarConverter&);    // Private
        ScalarConverter& operator=(const ScalarConverter&); // Private
        ~ScalarConverter();                         // Private
        
    public:
        static void convert(const std::string& input);  // Static
};
```

**Usage** :
```cpp
ScalarConverter::convert("42");     // OK
ScalarConverter obj;                // ❌ Erreur (constructeur privé)
```

#### 3. **Détection du type d'entrée**

```cpp
static void convert(const std::string& input) {
    // 1. Détecter le type
    if (isChar(input))
        convertChar(input);
    else if (isInt(input))
        convertInt(input);
    else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);
    else if (isPseudoLiteral(input))
        convertPseudo(input);
    else
        std::cout << "Invalid input" << std::endl;
}
```

#### 4. **Conversions entre types scalaires**

**Cast C++ (style fonctionnel)** :
```cpp
int i = 42;
char c = static_cast<char>(i);      // C++
float f = static_cast<float>(i);
double d = static_cast<double>(i);
```

**Cast C (à éviter en C++)** :
```cpp
char c = (char)i;     // Style C
```

#### 5. **Gestion des cas impossibles**

```cpp
void displayConversions(const std::string& input) {
    // char
    if (/* impossible */)
        std::cout << "char: impossible" << std::endl;
    else if (/* non displayable */)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    
    // int
    if (/* overflow ou nan/inf */)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    
    // float
    std::cout << "float: " << std::fixed << std::setprecision(1) 
              << f << "f" << std::endl;
    
    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << d << std::endl;
}
```

#### 6. **Pseudo-littéraux spéciaux**

```cpp
bool isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "-inf" ||
            str == "+inff" || str == "-inff");
}

// Gestion :
if (str == "nanf" || str == "nan") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}
```

#### 7. **Fonctions utiles**

```cpp
#include <cstdlib>  // strtod, strtof, strtol
#include <climits>  // INT_MAX, INT_MIN
#include <cmath>    // isnan, isinf
#include <limits>   // numeric_limits

// Conversion string → double
double d = std::strtod(str.c_str(), NULL);

// Vérifier si NaN ou inf
if (std::isnan(d)) { /* ... */ }
if (std::isinf(d)) { /* ... */ }

// Limites
if (d > INT_MAX || d < INT_MIN) {
    std::cout << "int: impossible" << std::endl;
}
```

#### 8. **Ce que vous apprenez**
- ✅ Détection de types depuis une string
- ✅ static_cast<>
- ✅ Classe non instanciable
- ✅ Méthodes statiques uniquement
- ✅ Gestion des limites de types
- ✅ Pseudo-littéraux (nan, inf)
- ✅ Conversion sécurisée

---

## 🔢 Exercice 01 : Serialization (Conversion pointeur ↔ entier)

### Concepts clés à maîtriser :

#### 1. **Le type uintptr_t**

```cpp
#include <stdint.h>

uintptr_t  // Type entier capable de stocker un pointeur
```

**Pourquoi uintptr_t ?**
- Garantit qu'un pointeur peut être converti en entier
- Taille adaptée à l'architecture (32 ou 64 bits)
- Conversion réversible

#### 2. **Sérialisation d'un pointeur**

```cpp
struct Data {
    int value;
    std::string name;
};

class Serializer {
    private:
        Serializer();  // Non instanciable
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
```

#### 3. **Implémentation de serialize()**

```cpp
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
    //     ^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //     Cast pour conversion bit à bit
}
```

#### 4. **Implémentation de deserialize()**

```cpp
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
    //     ^^^^^^^^^^^^^^^^^^^^^^^^^
    //     Conversion inverse
}
```

#### 5. **reinterpret_cast**

**Utilisation** : Conversion bit à bit (sans vérification)
```cpp
int* ptr = new int(42);
uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
int* ptr2 = reinterpret_cast<int*>(addr);
// ptr == ptr2 ✅
```

**Attention** : Très dangereux si mal utilisé !
```cpp
int i = 42;
float* f = reinterpret_cast<float*>(&i);  // ⚠️ Comportement indéfini
```

#### 6. **Test de réversibilité**

```cpp
Data* original = new Data;
original->value = 42;
original->name = "test";

uintptr_t serialized = Serializer::serialize(original);
Data* deserialized = Serializer::deserialize(serialized);

// Vérifications
assert(original == deserialized);
assert(deserialized->value == 42);
assert(deserialized->name == "test");

delete original;
```

#### 7. **Ce que vous apprenez**
- ✅ reinterpret_cast<>
- ✅ Type uintptr_t
- ✅ Sérialisation de pointeurs
- ✅ Conversion réversible
- ✅ Manipulation bas niveau

---

## 🎯 Exercice 02 : Identify real type (dynamic_cast et RTTI)

### Concepts clés à maîtriser :

#### 1. **Hiérarchie de classes**

```cpp
class Base {
    public:
        virtual ~Base() {}  // Destructeur virtuel obligatoire pour RTTI
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

#### 2. **Génération aléatoire**

```cpp
Base* generate() {
    srand(time(NULL));
    int random = rand() % 3;
    
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}
```

#### 3. **dynamic_cast avec pointeur**

```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
```

**Avec pointeur** :
- Retourne `NULL` si le cast échoue
- Pas d'exception

#### 4. **dynamic_cast avec référence**

```cpp
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}
```

**Avec référence** :
- Lance `std::bad_cast` si le cast échoue
- Utilise les exceptions

#### 5. **RTTI (Run-Time Type Information)**

**Nécessite** :
- Au moins une méthode virtuelle dans la classe de base
- Option de compilation `-frtti` (activée par défaut)

```cpp
#include <typeinfo>

Base* p = generate();
std::cout << typeid(*p).name() << std::endl;  // Affiche le nom du type
```

#### 6. **Comparaison des casts**

**dynamic_cast** :
```cpp
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);  // Vérifie à l'exécution
```

**static_cast** :
```cpp
Base* base = new Derived();
Derived* derived = static_cast<Derived*>(base);  // Pas de vérification !
```

**reinterpret_cast** :
```cpp
int* i = new int(42);
float* f = reinterpret_cast<float*>(i);  // Conversion bit à bit
```

**const_cast** :
```cpp
const int* ci = new int(42);
int* i = const_cast<int*>(ci);  // Retire const (dangereux!)
```

#### 7. **Ce que vous apprenez**
- ✅ dynamic_cast<>
- ✅ RTTI (typeid)
- ✅ std::bad_cast
- ✅ Différence cast pointeur vs référence
- ✅ Identification de type à l'exécution

---

## 🎓 Résumé des compétences acquises (Module 06)

### 1. **Les 4 casts C++**
- **static_cast** : Conversions "normales"
- **dynamic_cast** : Downcasting sécurisé (avec RTTI)
- **reinterpret_cast** : Conversion bit à bit
- **const_cast** : Modifier const/volatile

### 2. **Conversions de types**
- String → types numériques
- Pointeur ↔ entier
- Types dérivés ↔ base
- Détection de type

### 3. **Classes statiques**
- Constructeurs privés
- Méthodes statiques uniquement
- Utility classes

### 4. **RTTI**
- dynamic_cast
- typeid
- Identification runtime

---

## ⚠️ Pièges courants à éviter

1. **Oublier le destructeur virtuel pour RTTI**
```cpp
class Base {
    public:
        virtual ~Base() {}  // ⚠️ Obligatoire pour dynamic_cast !
};
```

2. **Utiliser static_cast au lieu de dynamic_cast**
```cpp
// ❌ Pas de vérification
Base* b = new Base();
Derived* d = static_cast<Derived*>(b);  // Dangereux !

// ✅ Vérifié
Derived* d = dynamic_cast<Derived*>(b);  // Retourne NULL
```

3. **Mauvaise gestion des limites**
```cpp
double d = 3e308;  // Très grand
int i = static_cast<int>(d);  // ⚠️ Overflow !

// Vérifier avant :
if (d > INT_MAX || d < INT_MIN)
    std::cout << "impossible" << std::endl;
```

4. **Oublier le 'f' pour les floats**
```cpp
float f = 42.42f;  // ✅ Correct
float f = 42.42;   // ❌ Double converti en float
```

5. **reinterpret_cast sur types incompatibles**
```cpp
int i = 42;
std::string* s = reinterpret_cast<std::string*>(&i);  // ❌ Danger !
```

---

## 📊 Tableau des casts C++

| Cast | Usage | Vérification | Risque |
|------|-------|--------------|--------|
| **static_cast** | Conversions standard | Compile-time | Moyen |
| **dynamic_cast** | Downcasting | Runtime | Faible |
| **reinterpret_cast** | Bit à bit | Aucune | Élevé |
| **const_cast** | Modifier const | Aucune | Élevé |
| **C-style cast** | (Type)value | Variable | Élevé |

---

## 🔄 Workflow de conversion sécurisée

```cpp
// 1. Vérifier la validité
if (input.empty() || !isValid(input)) {
    std::cout << "Invalid input" << std::endl;
    return;
}

// 2. Détecter le type
Type type = detectType(input);

// 3. Convertir avec gestion d'erreur
try {
    double d = convertToDouble(input);
    
    // 4. Vérifier les limites
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

---

## 💡 Concepts pour les modules suivants

Ce module prépare pour :
- **Module 07** : Templates (généricité)
- **Module 08** : Conteneurs STL
- **Module 09** : Algorithmes STL

---

## 📖 Pour aller plus loin

- **C++11 casts** : `std::static_pointer_cast`, etc.
- **Type traits** : `std::is_same`, `std::is_base_of`
- **SFINAE** : Substitution Failure Is Not An Error
- **Concepts** (C++20) : Contraintes sur les types
- **std::any** (C++17) : Type-safe container
- **std::variant** (C++17) : Union type-safe

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_06 - Casts et conversions de types
