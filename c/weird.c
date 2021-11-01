%:include <stdio.h>

int main()
<%
    int arr<::> = <% 1, 2, 3, 4 %>;

    for (int i = 0; i < sizeof(arr) / sizeof(arr<:0:>); i++)
    <%
        printf("%d\n", arr<:i:>);
    %>
%>
