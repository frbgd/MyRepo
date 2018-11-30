using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;

namespace WebApplication2
{
    public class ErrorHandlingMiddleware
    {
        RequestDelegate _next;
        public ErrorHandlingMiddleware(RequestDelegate next)
        {
            _next = next;
        }
        public async Task InvokeAsync(HttpContext context)
        {
            await _next(context);
            if (context.Response.StatusCode == 403)
                await context.Response.WriteAsync("Acces Denied");
            else if (context.Response.StatusCode == 404)
                await context.Response.WriteAsync("Not Found");
        }
    }
}
