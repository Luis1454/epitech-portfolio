FROM maven:3.8.4-jdk-11-slim as builder
COPY . /app
WORKDIR /app
RUN mvn dependency:resolve
RUN mvn package
FROM openjdk:11-jre-slim
EXPOSE 80
COPY --from=builder /app/target/worker-jar-with-dependencies.jar ./worker-jar-with-dependencies.jar
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]