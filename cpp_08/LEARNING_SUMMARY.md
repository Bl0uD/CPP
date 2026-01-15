# CPP Module 08 - Conteneurs STL et Templates avancés

## 📚 Vue d'ensemble
Ce module approfondit l'utilisation des **conteneurs STL**, des **itérateurs** et des **templates avancés**. Vous apprendrez à manipuler les conteneurs existants et à créer vos propres conteneurs avec des fonctionnalités personnalisées.

---

## 🔍 Exercice 00 : easyfind - Recherche dans un conteneur

### Concepts clés à maîtriser :

#### 1. **Templates de fonctions génériques**
```cpp
template <typename T>
typename T::iterator easyfind(T &container, int n);
```
- Template fonctionnant avec **n'importe quel conteneur**
- `typename T::iterator` : type dépendant du template (nécessite `typename`)

#### 2. **Algorithmes STL - std::find()**
```cpp
std::find(container.begin(), container.end(), n);
```
- Algorithme de `<algorithm>` pour la recherche linéaire
- Retourne un **itérateur** vers l'élément trouvé
- Retourne `container.end()` si non trouvé (idiome STL standard)

#### 3. **Itérateurs - Abstraction universelle**
```cpp
typename T::iterator it = easyfind(v, 5);
if (it != v.end())
    std::cout << *it << std::endl;
```
- `begin()` → premier élément
- `end()` → position après le dernier (sentinelle)
- Déréférencement avec `*it`
- Fonctionne avec `vector`, `list`, `deque`, etc.

#### 4. **Gestion d'erreur : Exception vs Valeur d'erreur**

**Option 1 : Exception**
```cpp
if (it == container.end())
    throw NotFoundExeption();
```
- Force la gestion de l'erreur
- Plus lourd en performance

**Option 2 : Valeur d'erreur (idiome STL)**
```cpp
return std::find(container.begin(), container.end(), n);
// Vérification : if (it != container.end())
```
- Plus léger et idiomatique
- Comme les algorithmes STL standard

#### 5. **Pourquoi pas d'index ?**
```cpp
// ❌ MAUVAIS : ne fonctionne pas avec list
container[i] == n

// ✅ BON : fonctionne avec tous les conteneurs
std::find(container.begin(), container.end(), n)
```
`std::list` n'a **pas d'opérateur []** (pas d'accès aléatoire).

#### 6. **Ce que vous apprenez**
- ✅ Créer des **templates de fonctions génériques**
- ✅ Utiliser les **algorithmes STL** (`<algorithm>`)
- ✅ Manipuler les **itérateurs**
- ✅ Comprendre **exception vs valeur d'erreur**
- ✅ Travailler avec différents **conteneurs séquentiels**
- ✅ Respecter les **idiomes C++ standard**

---

## 📊 Exercice 01 : Span - Calcul de portée

### Concepts clés à maîtriser :

#### 1. **Encapsulation d'un conteneur STL**
```cpp
class Span
{
private:
    unsigned int        _N;      // Capacité max
    std::vector<int>    _v;      // Stockage des nombres
};
```
- **Wrapper** autour de `std::vector<int>`
- Ajoute des **contraintes métier** (capacité limitée)
- Ajoute des **fonctionnalités spécifiques** (spans)

#### 2. **Gestion de capacité avec exceptions**
```cpp
void Span::addNumber(int n)
{
    if (_v.size() >= _N)
        throw FullContainerException();
    _v.push_back(n);
}
```
- Validation avant insertion
- Exception custom imbriquée

#### 3. **Ajout par range d'itérateurs**
```cpp
void Span::addNumber(std::vector<int>::iterator begin, 
                     std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) > _N)
        throw FullContainerException();
    _v.insert(_v.end(), begin, end);
}
```
- **`std::distance()`** : calcule le nombre d'éléments entre deux itérateurs
- **`vector::insert()`** : insertion en masse efficace
- Permet d'ajouter des milliers d'éléments en une fois

#### 4. **Algorithme shortestSpan - Utilisation de std::sort()**

```cpp
int Span::shortestSpan()
{
    if (_v.size() <= 1)
        throw NotEnoughNumbersException();
    
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    
    int min = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i-1] < min)
            min = tmp[i] - tmp[i-1];
    }
    return min;
}
```

**Pourquoi std::sort() ?**
```
Sans tri : [9, 1, 17, 3, 5]
- Comparer toutes les paires : 9-1, 9-17, 9-3, 9-5, 1-17, 1-3, ...
- Complexité : O(N²) avec N*(N-1)/2 comparaisons

Avec tri : [1, 3, 5, 9, 17]
- Comparer seulement les voisins : 3-1=2, 5-3=2, 9-5=4, 17-9=8
- Complexité : O(N log N) pour le tri + O(N) pour la recherche
- La plus petite différence est FORCÉMENT entre deux voisins !
```

**Étapes de l'algorithme :**
1. **Copie** : `tmp = _v` (préserve l'ordre original)
2. **Tri** : `std::sort()` met les nombres adjacents proches ensemble
3. **Recherche** : parcours linéaire des différences adjacentes
4. **Minimum** : garde la plus petite différence trouvée

#### 5. **Algorithme longestSpan**
```cpp
int Span::longestSpan()
{
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}
```
- Plus simple : différence entre max et min
- Après tri : `max = tmp[size-1]`, `min = tmp[0]`

#### 6. **Exceptions imbriquées**
```cpp
class FullContainerException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Container is full";
    }
};
```
- Classe imbriquée dans `Span`
- Accessible via `Span::FullContainerException`

#### 7. **Ce que vous apprenez**
- ✅ **Encapsuler** un conteneur STL dans une classe
- ✅ **Utiliser std::sort()** pour optimiser un algorithme
- ✅ **Manipuler des ranges** d'itérateurs
- ✅ **Créer des exceptions custom** imbriquées
- ✅ **Surcharger des méthodes** pour plus de flexibilité
- ✅ **Comprendre la complexité algorithmique** (O(N²) → O(N log N))

---

## 🧬 Exercice 02 : MutantStack - Stack avec itérateurs

### Concepts clés à maîtriser :

#### 1. **Héritage d'un conteneur STL**
```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
    // ...
};
```
- **Héritage public** de `std::stack<T>`
- Hérite de toutes les méthodes : `push()`, `pop()`, `top()`, `size()`, `empty()`
- Ajoute de nouvelles fonctionnalités (itérateurs)

#### 2. **Accès au conteneur sous-jacent protégé**
```cpp
// std::stack utilise un conteneur interne protégé
template <typename T>
class stack
{
protected:
    container_type c;  // Par défaut std::deque<T>
};
```

**Dans MutantStack :**
```cpp
iterator begin() { return this->c.begin(); }
iterator end()   { return this->c.end(); }
```
- **`this->c`** : accès au membre protégé hérité
- `c` est le conteneur interne (par défaut `std::deque<T>`)
- Permet d'exposer les itérateurs du conteneur sous-jacent

#### 3. **Typedef d'itérateurs imbriqués**
```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
typedef typename std::stack<T>::container_type::const_iterator const_iterator;
typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
```

**Décomposition :**
- `std::stack<T>::container_type` → type du conteneur sous-jacent (`std::deque<T>`)
- `::iterator` → type de l'itérateur de ce conteneur
- **`typename`** nécessaire car type dépendant d'un template

#### 4. **Syntaxe avancée des templates**

**this-> dans les templates héritant**
```cpp
// ✅ BON
return this->c.begin();

// ❌ Erreur en C++98
return c.begin();
```
- Dans un template héritant d'une classe template
- Le compilateur ne sait pas si `c` existe avant l'instanciation
- `this->` force la recherche dans la classe de base

**typename pour les types dépendants**
```cpp
typename MutantStack<T>::iterator it;  // ✅
MutantStack<T>::iterator it;           // ❌
```
- `iterator` dépend du template `T`
- `typename` lève l'ambiguïté (type vs valeur)

#### 5. **Pourquoi std::stack n'a pas d'itérateurs ?**

**Design de std::stack :**
- **Adaptateur de conteneur** (wrapper autour de deque/vector/list)
- Interface **LIFO** (Last In First Out) stricte
- N'expose que `top()`, `push()`, `pop()`
- **Restriction volontaire** : force l'utilisation correcte (discipline LIFO)

**MutantStack brise cette discipline :**
- Ajoute `begin()`, `end()`, `rbegin()`, `rend()`
- Permet l'itération complète
- "Mutant" = stack + itérateurs (hybride)

#### 6. **Utilisation pratique**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

// Itération comme un conteneur normal
for (MutantStack<int>::iterator it = mstack.begin(); 
     it != mstack.end(); ++it)
{
    std::cout << *it << " ";
}
```

#### 7. **Comparaison avec std::list**
```cpp
// Avec MutantStack
MutantStack<int> mstack;
mstack.push(5);          // Ajout
mstack.top();            // Accès au sommet
mstack.pop();            // Retrait

// Équivalent avec std::list
std::list<int> lst;
lst.push_back(5);        // Ajout
lst.back();              // Accès au dernier
lst.pop_back();          // Retrait
```
Les deux permettent l'itération, mais MutantStack garde l'interface LIFO.

#### 8. **Architecture en couches**
```
┌─────────────────────────────────┐
│      MutantStack<T>             │  (Ajoute itérateurs)
│  + begin(), end(), rbegin()...  │
└────────────┬────────────────────┘
             │ hérite de
┌────────────▼────────────────────┐
│       std::stack<T>             │  (Interface LIFO)
│  + push(), pop(), top()...      │
└────────────┬────────────────────┘
             │ utilise
┌────────────▼────────────────────┐
│    std::deque<T> (ou autre)     │  (Stockage réel)
│  + begin(), end(), []...        │
└─────────────────────────────────┘
```

#### 9. **Ce que vous apprenez**
- ✅ **Hériter** d'une classe template STL
- ✅ **Accéder** aux membres protégés d'une classe parente
- ✅ **Exposer** le conteneur sous-jacent via des itérateurs
- ✅ **Typedef** de types imbriqués complexes avec `typename`
- ✅ **Adaptateurs de conteneurs** (design pattern)
- ✅ **Syntaxe avancée** des templates (this->, typename, ::)
- ✅ **Comprendre** les choix de design de la STL

---

## 🎓 Résumé des compétences acquises (Module 08)

### 1. **Conteneurs STL (ex00)**
- Utiliser les algorithmes STL (`std::find`)
- Comprendre le rôle des itérateurs
- Exception vs valeur d'erreur (idiomes C++)
- Généricité avec les templates

### 2. **Manipulation de conteneurs (ex01)**
- Encapsuler et étendre `std::vector`
- Utiliser `std::sort()` pour optimiser
- Comprendre la complexité algorithmique
- `std::distance()` et ranges d'itérateurs
- Exceptions custom imbriquées

### 3. **Héritage de templates (ex02)**
- Hériter d'une classe template STL
- Accéder aux membres protégés
- Typedef de types imbriqués complexes
- Syntaxe avancée (`typename`, `this->`)
- Concept d'adaptateur de conteneur

### 4. **Concepts C++ avancés**
- **Itérateurs** : Abstraction universelle de parcours
- **Algorithmes STL** : Code générique réutilisable
- **Adaptateurs** : Modifier l'interface d'un conteneur
- **Type traits** : Extraction de types dépendants

---

## 📊 Tableau de comparaison des conteneurs

| Conteneur | Accès | Insertion début | Insertion fin | Itérateurs | Cas d'usage |
|-----------|-------|-----------------|---------------|------------|-------------|
| `vector` | O(1) | O(N) | O(1) amortized | Random access | Tableau dynamique |
| `list` | O(N) | O(1) | O(1) | Bidirectional | Insertions fréquentes |
| `deque` | O(1) | O(1) | O(1) | Random access | File/Pile |
| `stack` | - | - | O(1) | ❌ Aucun | LIFO strict |
| `MutantStack` | - | - | O(1) | ✅ Tous | LIFO + itération |

---

## ⚠️ Pièges courants à éviter

1. **Ne pas utiliser `[]` avec `list`** → Pas d'accès aléatoire
2. **Oublier `typename`** pour les types dépendants → Erreur de compilation
3. **Ne pas copier avant `std::sort()`** si on veut préserver l'ordre original
4. **Oublier `this->`** dans les templates hérités → Membre non trouvé
5. **Comparer complexité O(N²) vs O(N log N)** pour choisir le bon algorithme

---

## 🔗 Lien avec la STL (Standard Template Library)

Ce que vous avez appris est au cœur de la STL :

**Algorithmes :**
- `std::find`, `std::sort`, `std::distance`
- `std::for_each`, `std::transform`, `std::accumulate`

**Conteneurs :**
- `std::vector`, `std::list`, `std::deque`
- `std::stack`, `std::queue`, `std::priority_queue`

**Itérateurs :**
- Input, Output, Forward, Bidirectional, Random Access
- `begin()`, `end()`, `rbegin()`, `rend()`

Vous comprenez maintenant comment la STL est construite !

---

## 📖 Pour aller plus loin

### Algorithmes STL utiles
- `std::minmax_element()` : trouve min et max en un parcours
- `std::adjacent_difference()` : calcule les différences adjacentes
- `std::nth_element()` : partitionnement partiel
- `std::binary_search()` : recherche dans un conteneur trié

### Itérateurs avancés
- `std::back_inserter()` : itérateur d'insertion
- `std::istream_iterator` : lire depuis un flux
- `std::reverse_iterator` : parcours inversé

### Autres adaptateurs
- `std::queue` : FIFO (First In First Out)
- `std::priority_queue` : Heap (élément max/min en tête)

### C++ moderne
- **Range-based for** (C++11) : `for (auto x : container)`
- **Lambdas** (C++11) : fonctions anonymes
- **std::ranges** (C++20) : itération modernisée
- **Concepts** (C++20) : contraintes sur les templates

---

## 🎯 Compétences maîtrisées

Après ce module, vous êtes capable de :
- ✅ Utiliser les **algorithmes STL** efficacement
- ✅ Manipuler tous les types d'**itérateurs**
- ✅ Créer des **wrappers** autour des conteneurs STL
- ✅ **Hériter** de classes template
- ✅ Utiliser la syntaxe avancée des templates (`typename`, `this->`)
- ✅ Comprendre la **complexité algorithmique** et optimiser
- ✅ Créer des **exceptions custom**
- ✅ Respecter les **idiomes C++ modernes**

**Vous êtes prêts pour les modules avancés ! 🚀**

---

**Date de création** : 15 janvier 2026  
**Module** : CPP_08 - STL Containers & Advanced Templates
