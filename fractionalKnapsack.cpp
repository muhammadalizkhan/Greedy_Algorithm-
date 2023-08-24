#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v) {
        valuePerWeight = static_cast<double>(value) / weight;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += item.valuePerWeight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    std::vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    double maxValue = fractionalKnapsack(capacity, items);
    std::cout << "Maximum value achievable: " << maxValue << std::endl;

    return 0;
}
