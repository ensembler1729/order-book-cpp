#pragma once

#include <format>
#include <list>

#include "Constants.h"
#include "OrderDirection.h"
#include "OrderType.h"
#include "Usings.h"

class Order {
  public:
    Order(OrderType orderType, OrderId orderId, OrderDirection direction,
          Price price, Quantity quantity)
        : type_{orderType}, id_{orderId}, direction_{direction}, price_{price},
          initialQuantity_{quantity}, remainingQuantity_{quantity} {}

    Order(OrderId id, OrderDirection direction, Quantity quantity)
        : Order(OrderType::Market, id, direction, Constants::InvalidPrice,
                quantity) {}

    OrderId GetOrderId() const { return id_; }
    OrderDirection GetOrderDirection() const { return direction_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return type_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const {
        return GetInitialQuantity() - GetRemainingQuantity();
    }
    bool IsFilled() const { return GetRemainingQuantity() == 0; }
    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity())
            throw std::logic_error(
                std::format("Order ({}) cannot be filled for more than its "
                            "remaining quantity.",
                            GetOrderId()));

        remainingQuantity_ -= quantity;
    }
    void ToGoodTillCancel(Price price) {
        if (GetOrderType() != OrderType::Market)
            throw std::logic_error(
                std::format("Order ({}) cannot have its price adjusted, only "
                            "market orders can.",
                            GetOrderId()));

        price_ = price;
        type_ = OrderType::GoodTillCancel;
    }

  private:
    OrderType type_;
    OrderId id_;
    OrderDirection direction_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;
