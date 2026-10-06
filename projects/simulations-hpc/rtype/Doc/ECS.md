# ECS Documentation
 
## Overview
The `ECS` class represents an **Entity-Component-System** framework designed for managing game entities, their components, and the systems that process them. It provides functionality to handle entities, components, and systems dynamically, while also managing networked clients using `asio` for communication.
 
---
 
## Key Features
 
### 1. Entity Management
- **Add Entities:**
  - `addEntity(std::shared_ptr<Entity> entity)`
  - `addEntity(std::size_t id, std::shared_ptr<Entity> entity)`
 
- **Remove Entities:**
  - `dropEntity(std::shared_ptr<Entity> const &entity)`
 
- **Entity Retrieval:**
  - `std::shared_ptr<Entity> getElement<Entity>(std::size_t idx)`
 
- **Count Entities:**
  - `std::size_t getNbEntities()` returns the total number of entities.
 
### 2. Component Management
- **Add Components:**
  - `addComponent(std::shared_ptr<Component> const &component)`
  - `addComponent(std::size_t id, std::shared_ptr<Component> const &component)`
 
- **Remove Components:**
  - `dropComponent(std::shared_ptr<Component> const &component)`
 
- **Component Retrieval:**
  - `SparseArray<C> getComponents()` returns all components of a specific type `C`.
 
### 3. System Management
- **Add Systems:**
  - `addSystem(std::shared_ptr<System> const &system)`
  - `addSystem(std::size_t id, std::shared_ptr<System> const &system)`
 
- **Remove Systems:**
  - `dropSystem(std::shared_ptr<System> const &system)`
 
- **System Retrieval:**
  - `std::shared_ptr<System> getElement<System>(std::size_t idx)`
 
### 4. Network Client Management
- **Manage Clients:**
  - `addClient(std::size_t id, asio::ip::udp::endpoint endpoint)` adds a client.
  - `removeClient(std::size_t id)` removes a client.
  - `std::unordered_map<uint64_t, asio::ip::udp::endpoint>& getClients()` retrieves the list of clients.
 
- **Last Endpoint:**
  - `setLastEndpoint(asio::ip::udp::endpoint endpoint)` sets the most recently accessed endpoint.
  - `asio::ip::udp::endpoint getLastEndpoint()` retrieves the last endpoint.
 
### 5. Utilities
- **Retrieve Elements:**
  - `getElementFromContainer<Element, Container>(const Container &container, size_t idx)` retrieves a specific element from a container by index.
 
- **Display Information:**
  - `info()` outputs details about the ECS state.
 
- **Update Loop:**
  - `update()` runs the update loop for all systems.
 
---
 
## Code Example
```cpp
ECS ecs;
 
// Add an entity
std::shared_ptr<Entity> entity = std::make_shared<Entity>();
ecs.addEntity(entity);
 
// Add a component to an entity
std::shared_ptr<Component> component = std::make_shared<Position>();
ecs.addComponent(component);
 
// Add a system
std::shared_ptr<System> system = std::make_shared<Gravity>();
ecs.addSystem(system);
 
// Retrieve components of type Position
SparseArray<Position> positions = ecs.getComponents<Position>();
 
// Update the ECS
ecs.update();
```
 
---
 
## Suggestions for Improvement
1. **Error Handling:**
   - Validate inputs when adding/removing entities, components, or systems to avoid runtime errors.
 
2. **Performance Optimization:**
   - Investigate the efficiency of `SparseArray` for large-scale ECS setups.
 
3. **Documentation:**
   - Add detailed comments for all methods and private members.
 
4. **Scalability:**
   - Implement threading or parallel processing for systems that can handle concurrent updates.
 
---
 
## Class Diagram (Simplified)
```
ECS
|
|-- SparseArray<Entity>
|-- SparseArray<Component>
|-- SparseArray<System>
|-- asio::ip::udp::endpoint
|-- std::unordered_map<uint64_t, asio::ip::udp::endpoint>
```
 
---
