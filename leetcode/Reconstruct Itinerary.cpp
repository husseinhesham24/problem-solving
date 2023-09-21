# @param {String[][]} tickets
# @return {String[]}
def find_itinerary(tickets)
  tickets = tickets.sort.reverse.group_by(&:first)
  route, stack = [], ["JFK"]
  while stack.any?
    stack << tickets[stack[-1]].pop()[1] while (tickets[stack[-1]] || []).any?
    route << stack.pop()
  end
  route.reverse
end