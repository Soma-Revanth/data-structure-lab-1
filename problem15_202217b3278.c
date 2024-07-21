#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Define the size of the hash table
#define TABLE_SIZE 10
 
// Define the key-value pair structure
typedef struct {
    int key;
    int value;
} HashItem;
 
// Define the hash table structure
typedef struct {
    HashItem** items;
    int size;
    int count;
} HashTable;
 
// Function to create a hash item
HashItem* create_item(int key, int value) {
    HashItem* item = (HashItem*) malloc(sizeof(HashItem));
    item->key = key;
    item->value = value;
    return item;
}
 
// Function to create a hash table
HashTable* create_table(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (HashItem**) calloc(table->size, sizeof(HashItem*));
    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }
    return table;
}
 
// Hash function
int hash_function(int key, int size) {
    return key % size;
}
 
// Insert function
void insert(HashTable* table, int key, int value) {
    HashItem* item = create_item(key, value);
    int index = hash_function(key, table->size);
 
    while (table->items[index] != NULL && table->items[index]->key != key) {
        index = (index + 1) % table->size;
    }
 
    if (table->items[index] == NULL) {
        table->count++;
    }
 
    table->items[index] = item;
}
 
// Search function
int search(HashTable* table, int key) {
    int index = hash_function(key, table->size);
 
    while (table->items[index] != NULL) {
        if (table->items[index]->key == key) {
            return table->items[index]->value;
        }
        index = (index + 1) % table->size;
    }
 
    return -1; // Key not found
}
 
// Delete function
void delete(HashTable* table, int key) {
    int index = hash_function(key, table->size);
 
    while (table->items[index] != NULL) {
        if (table->items[index]->key == key) {
            table->items[index] = NULL;
            table->count--;
            return;
        }
        index = (index + 1) % table->size;
    }
}
 
// Rehash function (optional)
void rehash(HashTable** table) {
    int old_size = (*table)->size;
    HashItem** old_items = (*table)->items;
 
    *table = create_table(old_size * 2);
 
    for (int i = 0; i < old_size; i++) {
        if (old_items[i] != NULL) {
            insert(*table, old_items[i]->key, old_items[i]->value);
        }
    }
 
    free(old_items);
}
 
// Function to print the hash table
void print_table(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (table->items[i] != NULL) {
            printf("Index %d: Key = %d, Value = %d\n", i, table->items[i]->key, table->items[i]->value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}
 
// Main function to demonstrate the hash table
int main() {
    HashTable* table = create_table(TABLE_SIZE);
 
    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
 
    printf("Search key 2: %d\n", search(table, 2));
    printf("Search key 5: %d\n", search(table, 5));
 
    print_table(table);
 
    delete(table, 2);
 
    printf("After deletion:\n");
    print_table(table);
 
    rehash(&table);
 
    printf("After rehashing:\n");
    print_table(table);
 
    return 0;
}