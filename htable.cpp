#include "htable.h"

HTable::HTable(QObject *parent)
    : QObject{parent}
{

}

bool HTable::inn_check(Estate *temp, HTable *list, QString k)
{
    if (list->find(k, list) != -1){
        int ind = list->find(k, list);
        if (list[ind].head->company == temp->getCompany()){
            return true;
        }
        return false;
    }
    return true;
}

bool HTable::is_key(QString key)
{
    static const QRegularExpression r(R"(^[0-9][0-9][-][0-9][0-9][0-9][0-9][0-9][0-9]$)");
    auto match = r.match(key);
    if (match.hasMatch())
        return true;
    else
        return false;
}

int HTable::hash(QString key)
{
    int keys = 0;
    std::string key2 = key.toStdString();
    for (int i = 0; i < key_len; i++) {
        keys += int(key2[i]) * int(key2[i]);
    }
    return keys % table_len;

}

int HTable::find(QString key, HTable *list)
{
    if (is_key(key)) {
        int index = list->hash(key);
        if (list != nullptr && list[index].head != nullptr){
            while (list[index].head->inn != key) {
                index = (index + 1) % table_len;
                if (list[index].head == nullptr)
                    return -1;
                if (index == list->hash(key)) {
                    return -1;
                }
            }
        }else
            return -1;
        return index;
    }
    else {
        return -1;
    }

}

void HTable::add_tab(Estate *temp, HTable *list)
{
    if (is_key(temp->getInn())) {
        int index = hash(temp->getInn());
        if (list != nullptr ){
            while (list[index].head != nullptr) {
                if (temp->getInnBuyer() == ""){
                    if (list[index].head->inn == temp->getInn() && list[index].head->product == temp->getProd() && temp->getCount() != 0){
                        list[index].head->count += temp->getCount();
                        return;
                    }
                    else
                        index = (index + 1) % table_len;

                }
                else
                    index = (index + 1) % table_len;
            }
        }
        Node* lst = new Node;
        lst->company = temp->getCompany();
        lst->inn = temp->getInn();
        lst->product = temp->getProd();
        lst->count = temp->getCount();
        lst->inn_buyer = temp->getInnBuyer();
        list[index].head = lst;
        size++;
    }

}

void HTable::del(QString key, HTable *list)
{
    if (is_key(key)) {
        int index = hash(key);
        for(;;) {
            if (list[index].head == nullptr){
                index = (index + 1) % table_len;
            }
            else if (list[index].head->inn == key){
                list[index].head = nullptr;
                index = (index + 1) % table_len;
                size--;
            }
            else
                index = (index + 1) % table_len;
            if (index == hash(key)) {
                return;
            }
        }
        return;
    }
    else {
        return;
    }
}

void HTable::del(QString key, QString prod, HTable *list)
{
    if (is_key(key) && list != nullptr) {
        int index = hash(key);
        for(;;) {
            if (list[index].head == nullptr){
                index = (index + 1) % table_len;
            }
            else if (list[index].head->inn == key && list[index].head->product == prod){
                list[index].head = nullptr;
                size--;
                return;
            }
            else
                index = (index + 1) % table_len;
            if (index == hash(key)) {
                return;
            }
        }
        return;
    }
    else {
        return;
    }

}

bool HTable::availability_in_sold(QString key, QString prod, HTable *list)
{
    if (list != nullptr){
        int index = hash(key);
        for (;;){
            if (list[index].head == nullptr){
                index = (index + 1) % table_len;
            }
            else if (list[index].head->inn == key){
                if (list[index].head->product == prod){
                    return true;
                }
            }
            else
                index = (index + 1) % table_len;
            if (index == hash(key))
                return false;
        }
    }
    return false;
}

QString HTable::prod(HTable *list, int i)
{
    return list[i].head->product;
}

QString HTable::comp(HTable *list, int i)
{
    return list[i].head->company;
}

QString HTable::in(HTable *list, int i)
{
    return list[i].head->inn;
}

QString HTable::inn_b(HTable *list, int i)
{
    return list[i].head->inn_buyer;
}

int HTable::cnt(HTable *list, int i)
{
    return list[i].head->count;
}

bool HTable::status(HTable *list, int i)
{
    if (list[i].head != nullptr)
        return true;
    return false;
}

bool HTable::comparison(Estate *temp, HTable *main)
{
    if (is_key(temp->getInn())) {
        int index = main->hash(temp->getInn());
        if (main != nullptr && main->status(main, index)){
            while (main[index].head != nullptr) {
                if (main[index].head->inn == temp->getInn() && main[index].head->product == temp->getProd() && main[index].head->count - temp->getCount() >= 0
                        && main->inn_check(temp, main, temp->getInnBuyer())){
                    main[index].head->count -= temp->getCount();
                    if (main[index].head->count == 0)
                        main[index].head = nullptr;
                    return true;
                }
                index = (index + 1) % table_len;
                if (!main->status(main, index))
                    return false;
                if (index == main->hash(temp->getInn())) {
                    return false;
                }
            }
        }
        else
            return false;
    }
    else {
        return false;
    }
}
