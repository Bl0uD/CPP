# CPP Module 09 - STL (Standard Template Library)

## 📚 Vue d'ensemble
Ce module explore les **conteneurs STL avancés** et les **algorithmes de tri complexes**. Focus sur `std::map`, `std::stack`, `std::deque`, `std::list` et l'implémentation de l'algorithme **Ford-Johnson (merge-insert sort)**.

---

## 💰 Exercice 00 : Bitcoin Exchange (std::map)

### Concepts clés à maîtriser :

#### 1. **Le conteneur std::map**
```cpp
#include <map>

std::map<std::string, double> _btcPrices;
// std::map<Clé, Valeur>
// - Clés triées automatiquement
// - Recherche O(log n)
// - Pas de doublons de clés
```

#### 2. **Insertion dans une map**
```cpp
// Méthode 1 : Opérateur []
_btcPrices["2024-01-01"] = 42000.50;

// Méthode 2 : insert()
_btcPrices.insert(std::make_pair("2024-01-02", 43000.00));

// Si la clé existe, [] écrase, insert() ne fait rien
```

#### 3. **Recherche dans une map**
```cpp
// find() retourne un itérateur
std::map<std::string, double>::iterator it = _btcPrices.find(date);

if (it != _btcPrices.end()) {
    // Clé trouvée
    std::cout << it->first << " : " << it->second << std::endl;
    //           ^^^^^^^^^ clé      ^^^^^^^^^^^^ valeur
}
```

#### 4. **lower_bound() - Recherche de la date inférieure**
```cpp
std::map<std::string, double>::iterator it = _btcPrices.lower_bound(date);
// Retourne un itérateur vers le premier élément >= date

if (it == _btcPrices.begin()) {
    // Date recherchée est avant la première date
    // Utiliser it (première date disponible)
} else {
    --it;  // Date précédente (plus proche inférieure)
}
```

**Exemple** :
```
Map : ["2020-01-01" → 7000], ["2020-06-01" → 9000], ["2021-01-01" → 40000]
Recherche : "2020-08-15"
lower_bound("2020-08-15") → "2021-01-01"
--it → "2020-06-01" ✅ (date inférieure la plus proche)
```

#### 5. **Parsing de fichier CSV**
```cpp
std::ifstream file("data.csv");
std::string line;

std::getline(file, line);  // Header (skip)

while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date, price;
    
    std::getline(ss, date, ',');   // Lire jusqu'à ','
    std::getline(ss, price, ',');
    
    _btcPrices[date] = std::atof(price.c_str());
}
```

#### 6. **Validation de dates**
```cpp
bool valideDate(std::string const &date) {
    // Format: YYYY-MM-DD (10 caractères)
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    // Extraction avec istringstream
    int year, month, day;
    char sep1, sep2;
    std::istringstream ss(date);
    ss >> year >> sep1 >> month >> sep2 >> day;
    
    // Validation des ranges
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Vérification jours/mois (30, 31, février)
    // Années bissextiles : (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
}
```

#### 7. **Ce que vous apprenez**
- ✅ **std::map** - conteneur associatif trié
- ✅ **find()** et **lower_bound()** pour la recherche
- ✅ Parsing de fichiers CSV
- ✅ **std::istringstream** pour le parsing de chaînes
- ✅ Validation de formats (dates, nombres)
- ✅ Gestion d'erreurs avec messages appropriés
- ✅ Différence entre opérateur [] et insert()

---

## 🔢 Exercice 01 : RPN - Reverse Polish Notation (std::stack)

### Concepts clés à maîtriser :

#### 1. **Le conteneur std::stack**
```cpp
#include <stack>

std::stack<double> _stack;
// LIFO (Last In, First Out) - Pile
// Pas d'itérateurs (accès restreint)
// Adapté pour RPN !
```

#### 2. **Opérations de base sur std::stack**
```cpp
_stack.push(42);          // Empiler
double top = _stack.top(); // Accéder au sommet (sans retirer)
_stack.pop();             // Dépiler (sans retourner la valeur)
bool empty = _stack.empty(); // Vérifier si vide
size_t size = _stack.size();  // Taille de la pile
```

#### 3. **Notation Polonaise Inversée (RPN)**

**Notation infixe** (normale) :
```
(3 + 4) * 5 = 35
```

**Notation postfixe** (RPN) :
```
3 4 + 5 *
```

**Algorithme** :
1. Pour chaque token :
   - Si **nombre** → empiler
   - Si **opérateur** → dépiler 2 valeurs, calculer, empiler résultat
2. Résultat final = sommet de la pile

#### 4. **Implémentation RPN**
```cpp
RPN::RPN(const std::string &inputStr) {
    std::stringstream ss(inputStr);
    std::string token;
    
    while (std::getline(ss, token, ' ')) {
        if (token.empty()) continue;
        
        if (isDigit(token)) {
            int num;
            std::stringstream(token) >> num;
            _stack.push(num);
        }
        else if (token == "+")
            executeStack(&RPN::plus);
        else if (token == "-")
            executeStack(&RPN::minus);
        else if (token == "*")
            executeStack(&RPN::multiply);
        else if (token == "/")
            executeStack(&RPN::divide);
        else
            throw InvalidArgException("Error: Invalid argument");
    }
}
```

#### 5. **Exécution des opérations**
```cpp
void RPN::executeStack(double (RPN::*f)(double, double)) {
    if (_stack.size() < 2)
        throw EmptyStackException("Error: Empty Stack");
    
    double a = _stack.top(); _stack.pop();
    double b = _stack.top(); _stack.pop();
    
    _stack.push((this->*f)(a, b));
    //          ^^^^^^^^^^^^^^^^^ Appel de pointeur de méthode
}

double RPN::plus(double a, double b) {
    return b + a;  // Attention à l'ordre !
}
```

**Pourquoi `b + a` et pas `a + b` ?**
```
Pile : [... 5, 3]
       ^a = 3 (top, dépilé en premier)
       ^b = 5 (dépilé en second)
Opération : 5 - 3 = 2 (pas 3 - 5 = -2)
```

#### 6. **Pointeurs de méthodes**
```cpp
// Déclaration du type
double (RPN::*f)(double, double);

// Assignation
f = &RPN::plus;

// Appel
(this->*f)(a, b);
```

#### 7. **Ce que vous apprenez**
- ✅ **std::stack** - pile LIFO
- ✅ Notation Polonaise Inversée (RPN)
- ✅ **Pointeurs de méthodes** de classe
- ✅ Parsing de chaîne avec **std::stringstream**
- ✅ Algorithme avec pile (stack-based algorithm)
- ✅ Gestion d'erreurs avec exceptions personnalisées

---

## 🔀 Exercice 02 : PmergeMe - Algorithme Ford-Johnson

### Concepts clés à maîtriser :

#### 1. **std::deque vs std::list**

**std::deque** (Double-Ended Queue) :
```cpp
#include <deque>

std::deque<int> dq;
dq.push_back(42);      // Ajout à la fin
dq.push_front(10);     // Ajout au début
dq[5] = 100;           // Accès aléatoire O(1)
dq.insert(dq.begin() + 3, 50); // Insertion O(n)
```

**std::list** (Liste doublement chaînée) :
```cpp
#include <list>

std::list<int> lst;
lst.push_back(42);     // Ajout à la fin
lst.push_front(10);    // Ajout au début
// lst[5] = 100;       // ❌ Pas d'accès aléatoire !
lst.insert(it, 50);    // Insertion O(1) si on a l'itérateur
```

**Comparaison** :

| Caractéristique | std::deque | std::list |
|----------------|------------|-----------|
| **Accès aléatoire** | ✅ O(1) | ❌ O(n) |
| **Insertion début/fin** | ✅ O(1) | ✅ O(1) |
| **Insertion milieu** | O(n) | ✅ O(1) avec itérateur |
| **Mémoire** | Blocs contigus | Nœuds éparpillés |
| **Cache-friendly** | ✅ Oui | ❌ Non |

#### 2. **Algorithme Ford-Johnson (Merge-Insert Sort)**

**Principe** :
1. **Pairing** : Grouper par paires et trier chaque paire
2. **Recursive sort** : Trier récursivement les plus grands éléments
3. **Main chain** : Créer la chaîne principale avec les plus grands
4. **Jacobsthal insertion** : Insérer les petits éléments dans un ordre optimal

**Avantage** :
- **Minimise le nombre de comparaisons**
- Optimal pour les petites listes (< 20 éléments)
- Complexité théorique meilleure que quicksort pour petites tailles

#### 3. **Suite de Jacobsthal**
```cpp
void generateJacobsthalNumbers(std::vector<size_t> &jacob, size_t max) {
    jacob.push_back(0);
    jacob.push_back(1);
    
    size_t i = 2;
    while (true) {
        size_t next = jacob[i - 1] + 2 * jacob[i - 2];
        if (next > max) break;
        jacob.push_back(next);
        i++;
    }
}

// Résultat : [0, 1, 1, 3, 5, 11, 21, 43, 85, ...]
```

**Pourquoi Jacobsthal ?**
- Ordre d'insertion **optimal** pour minimiser les comparaisons
- Basé sur la recherche dichotomique
- Exploite la structure déjà triée

#### 4. **Insertion binaire (Binary insertion)**
```cpp
void binaryInsertDeque(std::deque<int> &mainChain, int value, size_t endPos) {
    size_t left = 0;
    size_t right = endPos;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        
        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    mainChain.insert(mainChain.begin() + left, value);
}
```

**Complexité** : O(log n) comparaisons + O(n) insertion

#### 5. **Implémentation séparée par conteneur**

**Pourquoi pas de template générique ?**
```cpp
// ❌ INTERDIT par le sujet
template <typename Container>
void fordJohnson(Container &container) { /* ... */ }
```

**✅ Implémentation séparée** :
```cpp
void fordJohnsonDeque(std::deque<int> &container) {
    // Utilise mainChain[mid] (accès aléatoire)
}

void fordJohnsonList(std::list<int> &container) {
    // Utilise std::advance() et std::lower_bound()
    // Pas d'accès par index !
}
```

**Raison** : Chaque conteneur a des **caractéristiques différentes** :
- `deque` → accès rapide par index
- `list` → insertion rapide avec itérateurs

#### 6. **Mesure du temps d'exécution**
```cpp
#include <ctime>

clock_t start = clock();
fordJohnsonDeque(_dequeStorage);
double time = static_cast<double>(clock() - start) * 1000000 / CLOCKS_PER_SEC;
//                                                    ^^^^^^^^^ Conversion en μs

std::cout << "Time to process a range of " << _dequeStorage.size() 
          << " elements with std::deque : " << time << " us" << std::endl;
```

#### 7. **Différences list vs deque dans l'implémentation**

**Pour deque (accès direct)** :
```cpp
// Accès direct
int value = mainChain[mid];

// Insertion à une position
mainChain.insert(mainChain.begin() + left, value);
```

**Pour list (itérateurs)** :
```cpp
// Accès avec avance
std::list<int>::iterator it = mainChain.begin();
std::advance(it, mid);
int value = *it;

// Insertion avec lower_bound
std::list<int>::iterator pos = std::lower_bound(mainChain.begin(), searchEnd, value);
mainChain.insert(pos, value);
```

#### 8. **Ce que vous apprenez**
- ✅ **std::deque** - tableau dynamique à deux extrémités
- ✅ **std::list** - liste doublement chaînée
- ✅ Différences entre conteneurs (trade-offs)
- ✅ **Algorithme Ford-Johnson** (merge-insert sort)
- ✅ **Suite de Jacobsthal** et ordre d'insertion optimal
- ✅ **Insertion binaire** (binary search insertion)
- ✅ **std::advance()** et **std::lower_bound()** pour les listes
- ✅ Mesure de **performances** (benchmarking)
- ✅ Implémentation spécifique par conteneur (pas de généricité)

---

## 🎓 Récapitulatif du Module 09

### Conteneurs utilisés :
1. **std::map** → Conteneur associatif trié (ex00)
2. **std::stack** → Pile LIFO (ex01)
3. **std::deque** → Tableau dynamique double-ended (ex02)
4. **std::list** → Liste doublement chaînée (ex02)

### Concepts fondamentaux :
- **Conteneurs associatifs** vs **séquentiels**
- **Adaptateurs de conteneurs** (stack)
- **Trade-offs** entre conteneurs (mémoire, performance, accès)
- **Algorithmes de tri complexes** (Ford-Johnson)
- **Recherche dichotomique** et insertion optimale

### Règles importantes :
- ⚠️ **Chaque exercice doit utiliser des conteneurs différents**
- ⚠️ **Pas de template générique pour ex02** (implémentation séparée)
- ⚠️ **Gestion de 3000+ éléments minimum pour ex02**
- ⚠️ **Mesure des performances obligatoire**

### Compétences acquises :
- ✅ Maîtrise approfondie de la **STL**
- ✅ Choix du **bon conteneur** selon le besoin
- ✅ Implémentation d'**algorithmes complexes**
- ✅ **Parsing** et validation de données
- ✅ **Benchmarking** et optimisation
- ✅ Compréhension des **structures de données** avancées

---

## 📊 Tableau comparatif des conteneurs STL

| Conteneur | Type | Accès | Insertion début | Insertion fin | Insertion milieu | Mémoire | Tri |
|-----------|------|-------|-----------------|---------------|------------------|---------|-----|
| **vector** | Séquentiel | O(1) | O(n) | O(1) amort. | O(n) | Contigüe | Non |
| **deque** | Séquentiel | O(1) | O(1) | O(1) | O(n) | Blocs | Non |
| **list** | Séquentiel | O(n) | O(1) | O(1) | O(1) | Nœuds | Non |
| **map** | Associatif | O(log n) | — | — | O(log n) | Nœuds | Oui |
| **set** | Associatif | O(log n) | — | — | O(log n) | Nœuds | Oui |
| **stack** | Adaptateur | Top only | — | O(1) push | — | Variable | Non |
| **queue** | Adaptateur | Front/Back | O(1) | O(1) | — | Variable | Non |

### Quand utiliser quel conteneur ?

**std::vector** :
- ✅ Accès aléatoire fréquent
- ✅ Insertions/suppressions à la fin
- ❌ Insertions au début ou milieu

**std::deque** :
- ✅ Insertions aux deux extrémités
- ✅ Accès aléatoire
- ❌ Insertions au milieu

**std::list** :
- ✅ Insertions/suppressions fréquentes partout
- ✅ Pas d'invalidation d'itérateurs
- ❌ Accès aléatoire rare

**std::map** :
- ✅ Recherche par clé
- ✅ Données triées
- ✅ Associations clé-valeur
- ❌ Pas de doublons de clés

**std::stack** :
- ✅ Structure LIFO (pile)
- ✅ Algorithmes basés sur pile (RPN, parsers)
- ❌ Besoin d'accès aux éléments intermédiaires

---

## 🚀 Optimisations et bonnes pratiques

### 1. Réserver de la mémoire (vector/deque)
```cpp
std::vector<int> v;
v.reserve(1000);  // Évite les réallocations
```

### 2. Utiliser emplace au lieu de push
```cpp
// ❌ Crée un temporaire puis copie
_map.insert(std::make_pair(key, value));

// ✅ Construction directe in-place
_map.emplace(key, value);
```

### 3. Préférer les algorithmes STL
```cpp
// ❌ Boucle manuelle
for (size_t i = 0; i < v.size(); i++)
    if (v[i] == value) return i;

// ✅ Algorithme STL
return std::find(v.begin(), v.end(), value);
```

### 4. Passer par référence const
```cpp
void process(const std::vector<int> &v);  // ✅ Pas de copie
void process(std::vector<int> v);         // ❌ Copie complète
```

### 5. Utiliser auto pour les itérateurs
```cpp
// ❌ Long et verbeux
std::map<std::string, double>::iterator it = map.find(key);

// ✅ Concis et lisible (C++11)
auto it = map.find(key);
```

---

## 📚 Ressources supplémentaires

### Documentation officielle :
- [cppreference.com/STL](https://en.cppreference.com/w/cpp/container)
- [cplusplus.com/reference/stl](http://www.cplusplus.com/reference/stl/)

### Algorithme Ford-Johnson :
- "The Art of Computer Programming, Vol 3" - Donald Knuth, p.184
- Merge-Insert Sort (algorithme hybride optimal pour petites tailles)

### Complexités algorithmiques :
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

---

**🎯 Félicitations ! Vous maîtrisez maintenant la STL et ses conteneurs avancés !**
