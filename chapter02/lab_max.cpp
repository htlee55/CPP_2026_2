

int list[10]{};

for (int& elem : list) {
    elem = rand() % 100 + 1;
    cout << elem << " ";
}

int max{list[0]};
for (int elem : list) {
    if (elem > max)
        max = elem;
}
cout << "최대값=" << max;
