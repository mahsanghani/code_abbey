int main() {
        int N, pos, min, max, input;
        vector<int> arr;
        vector<int>::iterator i;
        cin >> N;
        for (int k = 1; k <= N; k++) {
                cin >> input;
                arr.push_back(input);
        }
        cin >> pos;
        arr.erase(arr.begin() + pos - 1);
        cin >> min >> max;
        arr.erase(arr.begin() + min - 1, arr.begin() +  max - 1);
        cout << arr.size() << endl;
        for (i = arr.begin(); i < arr.end(); i++)
                cout << *i << " ";
        return 0;
}
