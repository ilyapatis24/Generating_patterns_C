#include <map>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>


struct SqlQuery {

    std::vector<std::string> column;
    std::string from;
    std::map<std::string, std::string> where;

};

class SqlSelectQueryBuilder {
public:
    constexpr bool BuildQuery() {
        return true;
    }

    const std::string makeQuery() {
        std::string result = getSelect() + getFrom() + getWhere() + ";\n";
        return result;
    }

    const std::string getSelect() {
        std::string select;
        std::stringstream queryStringStream;
        for (auto it = query.column.begin(); it != query.column.end(); it++) {
            if (it != query.column.begin()) {
                queryStringStream << ", ";
            }
            queryStringStream << *it;
        }
        if (query.column.empty() && !query.from.empty()) select = "SELECT * ";
        else select = "SELECT " + queryStringStream.str() + " ";
        return select;
    }

    const std::string getFrom() {
        std::string from = "FROM " + query.from + " ";
        return from;
    }

    const std::string getWhere() {
        std::string where;
        std::stringstream queryStringStream;
        for (auto it = query.where.begin(); it != query.where.end(); it++) {
            if (it != query.where.begin()) {
                queryStringStream << " AND ";
            }
            queryStringStream << it->first + "=" + it->second;
            where = "WHERE " + queryStringStream.str();
        }
        return where;
    }

    SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept {
        query.column.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& column) noexcept {
        query.column = column;
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) noexcept {
        query.from = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) noexcept {
        query.where[key] = value;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        query.where = kv;
        return *this;
    }

private:
    SqlQuery query;
};

int main(int argc, char** argv) {
    SqlSelectQueryBuilder query_builder;

    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    query_builder.AddFrom("students");
    std::cout << query_builder.makeQuery() << "\n";
    static_assert(query_builder.BuildQuery(),
        "Error in making query");

    query_builder.AddColumns({ "age", "sex" });
    query_builder.AddWhere({ { "age", "20" }, { "sex", "male" } });
    std::cout << query_builder.makeQuery() << "\n";
    static_assert(query_builder.BuildQuery(),
        "SELECT name, phone FROM students WHERE age=20 AND sex=male;");
    return 0;
}